/*
* Hunter Roseborough & Ethan Taylor
* 
* This is our lotter game that gets 7 numbers form the user
* and generates 7 random numbers then compares them and dispays how many matched
* and if they won or lossed any money. Also displays the winning numbers
*/

#include <iostream>
#include <limits>
#include <fstream>
#include <sstream> 



using namespace std;
int main() {
	//Starting varibles for a first time play
	string gameOver = "";
	int playTimes;
	int money = 50;

	//title
	cout << "Welcome to lottery101" << endl;
	cout << "Enter 7 numbers for a chance to win 70,000,000!" << endl;
	cout << "brought to you by Ethan and Hunter" << endl << endl;
	cout << "Your amount: $";
	cout << money << endl;
	//this is asking the user if they want to play the game
	while (true) {
		cout << "Would you like to play ? (y/n)" << endl;
		cin >> gameOver;
		if (gameOver == "y" || gameOver == "n") {
			break;
		}
		else{
			cout << "Invaild input only enter (y/n)\n";
		}
	}
	cout << endl;

	//looped most of program for play again
	while (gameOver != "n") {
		//asking the user how many times they want to play
		//and checking if they input a vaild number
		while (true) {
			cout << "How many times would you like to play" << endl;
			cin >> playTimes;
			if (playTimes < 1 || cin.fail())
			{
				cout << "Please enter a valid number greater then 0\n";
				//clearing the input when invalid
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				break;
			}
		}
		cout << endl;
		for (int i = 0; i < playTimes; i++) {
			money -= 5;
			//vars for run through of loop gets reset on after play again is y
			int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, total = 0;
			int randTemp, rand1 = 0, rand2 = 0, rand3 = 0, rand4 = 0, rand5 = 0, rand6 = 0, rand7 = 0;
			int randNow = 1, counter = 0;
			bool leave = false;
			

			//creating 7 random numbers
			int elapsed_seconds = time(nullptr);
			srand(elapsed_seconds);
			//for loop for generating the 7 random numebrs
			while (counter < 7) {
				randTemp = rand() % 50;
				randTemp = randTemp + 1;

				//checking if he numbers are duplicates
				if (randTemp == rand1 || randTemp == rand2 || randTemp == rand3 || randTemp == rand4 || randTemp == rand5 || randTemp == rand6 || randTemp == rand7) {

				}
				else
				{
					//using a switch statment to assign the current random number the the right varible for storing the random numbers
					switch (randNow)
					{
					case 1:
						rand1 = randTemp;
					case 2:
						rand2 = randTemp;
					case 3:
						rand3 = randTemp;
					case 4:
						rand4 = randTemp;
					case 5:
						rand5 = randTemp;
					case 6:
						rand6 = randTemp;
					case 7:
						rand7 = randTemp;
					}
					randNow++;
					counter++;
				}

			}
			//stroing the winning numbers in a file
			ofstream randomNumberFile;
			randomNumberFile.open("Group2LottoFile.txt", ios::out | ios::trunc );
			randomNumberFile << "This weeks winning numbers\n";
			randomNumberFile << rand1 << "\n";
			randomNumberFile << rand2 << "\n";
			randomNumberFile << rand3 << "\n";
			randomNumberFile << rand4 << "\n";
			randomNumberFile << rand5 << "\n";
			randomNumberFile << rand6 << "\n";
			randomNumberFile << rand7 << "\n";
			randomNumberFile.close();
			//for testing purposes
			//cout << rand1 << " " << rand2 << " " << rand3 << " " << rand4 << " " << rand5 << " " << rand6 << " " << rand7 << endl;

			//displaying the users money
			cout << "Money: ";
			cout << money << endl;

			//getting numbers from user and checking if between 1 and 50 and that it is not a duplicate
			ofstream playerNumberFile;
			playerNumberFile.open("PlayerNumbers.txt", ios::out | ios::trunc);
			while (!leave) {
				cout << "Enter the 1st number between 1 - 50" << endl;
				cin >> num1;
				if (num1 > 50 || num1 < 1 || cin.fail())
				{
					cout << "First Number invalid try again\n";
					//clearing the input when invalid
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					playerNumberFile << num1 << "\n";
					leave = true; //flag to see if the number inputed is valid
				}
			}

			leave = false;//resetting the flag

			while (!leave) {
				cout << "Enter 2nd number between 1 - 50" << endl;
				cin >> num2;
				if (num2 > 50 || num2 < 1 || cin.fail())
				{
					cout << "second Number invalid try again\n";
					//clearing the input when invalid
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else if (num2 == num1) {
					cout << "Already entered ths number\n";
				}
				else
				{
					playerNumberFile << num2 << "\n";
					leave = true;
				}
			}

			leave = false;

			while (!leave) {
				cout << "Enter 3rd number between 1 - 50" << endl;
				cin >> num3;
				if (num3 > 50 || num3 < 1 || cin.fail())
				{
					cout << "Thrid Number invalid try again\n";
					//clearing the input when invalid
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else if (num3 == num1 || num3 == num2) {
					cout << "Already entered this number\n";
				}
				else
				{
					playerNumberFile << num3 << "\n";
					leave = true;
				}
			}

			leave = false;

			while (!leave) {
				cout << "Enter 4th number between 1 - 50" << endl;
				cin >> num4;
				if (num4 > 50 || num4 < 1 || cin.fail())
				{
					cout << "4th Number invalid try again\n";
					//clearing the input when invalid
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else if (num4 == num1 || num4 == num2 || num4 == num3) {
					cout << "Already entered this number\n";
				}
				else
				{
					playerNumberFile << num4 << "\n";
					leave = true;
				}
			}

			leave = false;

			while (!leave) {
				cout << "Enter 5th number between 1 - 50" << endl;
				cin >> num5;
				if (num5 > 50 || num5 < 1 || cin.fail())
				{
					cout << "5th Number invalid try again\n";
					//clearing the input when invalid
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else if (num5 == num1 || num5 == num2 || num5 == num3 || num5 == num4) {
					cout << "Already entered this number\n";
				}
				else
				{
					playerNumberFile << num5 << "\n";
					leave = true;
				}
			}

			leave = false;

			while (!leave) {
				cout << "Enter 6th number between 1 - 50" << endl;
				cin >> num6;
				if (num6 > 50 || num6 < 1 || cin.fail())
				{
					cout << "6th Number invalid try again\n";
					//clearing the input when invalid
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else if (num6 == num1 || num6 == num2 || num6 == num3 || num6 == num4 || num6 == num5) {
					cout << "Already entered this number\n";
				}
				else
				{
					playerNumberFile << num6 << "\n";
					leave = true;
				}
			}

			leave = false;

			while (!leave) {
				cout << "Enter 7th number between 1 - 50" << endl;
				cin >> num7;
				if (num7 > 50 || num7 < 1 || cin.fail())
				{
					cout << "7th Number invalid try again\n";
					//clearing the input when invalid
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else if (num7 == num1 || num7 == num2 || num7 == num3 || num7 == num4 || num7 == num5 || num7 == num6) {
					cout << "Already entered this number\n";
				}
				else
				{
					playerNumberFile << num7 << "\n";
					leave = true;
				}
			}
			playerNumberFile.close();

			//checking to see if any of the users inputs match the computer generated numbers 
			if (num1 == rand1 || num1 == rand2 || num1 == rand3 || num1 == rand4 || num1 == rand5 || num1 == rand6 || num1 == rand7) {
				total = total + 1;
			}
			if (num2 == rand1 || num2 == rand2 || num2 == rand3 || num2 == rand4 || num2 == rand5 || num2 == rand6 || num2 == rand7) {
				total = total + 1;
			}
			if (num3 == rand1 || num3 == rand2 || num3 == rand3 || num3 == rand4 || num3 == rand5 || num3 == rand6 || num3 == rand7) {
				total = total + 1;
			}
			if (num4 == rand1 || num4 == rand2 || num4 == rand3 || num4 == rand4 || num4 == rand5 || num4 == rand6 || num4 == rand7) {
				total = total + 1;
			}
			if (num5 == rand1 || num5 == rand2 || num5 == rand3 || num5 == rand4 || num5 == rand5 || num5 == rand6 || num5 == rand7) {
				total = total + 1;
			}
			if (num6 == rand1 || num6 == rand2 || num6 == rand3 || num6 == rand4 || num6 == rand5 || num6 == rand6 || num6 == rand7) {
				total = total + 1;
			}
			if (num7 == rand1 || num7 == rand2 || num7 == rand3 || num7 == rand4 || num7 == rand5 || num7 == rand6 || num7 == rand7) {
				total = total + 1;
			}

			//checking the total amount of number matched and dislaying they're winnings and added it to they're money
			switch (total)
			{
			case 0:
				cout << "0 numbers matched lost 5$\n";
				money -= 5;
				break;
			case 1:
				cout << "1 number mathced you lose try again\n";
				break;
			case 2:
				cout << "2 numbers matched you lose try agian\n";
				break;
			case 3:
				cout << "3 numbers matched! Refunded!\n";
				money += 5;
				break;
			case 4:
				cout << "4 numbers matched you Won 20$\n";
				money += 20;
				break;
			case 5:
				cout << "5 numbers matched you Won 1000$\n";
				money += 1000;
			case 6:
				cout << "6 numbers matched you Won 100,000\n";
				money += 1000000;
			case 7:
				cout << "7 numbers matched you Won 70,000,000\n";
				money += 70000000;
				break;
			}//end of switch
			cout << endl;

			//displaying the winning numbers from the text file
			ifstream WinningNumbers;
			WinningNumbers.open("Group2LottoFile.txt");
			if (WinningNumbers) {
				string line;
				while (getline(WinningNumbers, line)) // read line from stream
					cout << line << '\n';
				int num;
				while (WinningNumbers >> num) //reads the numbers from the file 
				{
					cout << num;
				}
				WinningNumbers.close();
			}
		}//end of counted loop
		//displaying the players money and asking to play again
		cout << "Money: ";
		cout << money << endl;
		cout << "Would you like to play again (y/n) for 5$ ?";
		cin >> gameOver;
	}//end of play again loop
	cout << "Thanks for playing!!!!";
}