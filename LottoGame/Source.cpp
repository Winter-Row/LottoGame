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
#include <vector>
using namespace std;

void display_title();
vector<int> get_user_numbers();
vector<int> generate_rand_nums();

int main() {
	//Starting varibles for a first time play
	vector<int> randNums(7);
	vector<int> userNums(7);
	string gameOver = "";
	string sameNums = "n";
	int playTimes;
	int money = 50;//setting the users starting amount of money

	display_title();
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
			
			randNums = generate_rand_nums();

			//stroing the winning numbers in a file
			ofstream randomNumberFile;
			randomNumberFile.open("Group2LottoFile.txt", ios::out | ios::trunc );
			randomNumberFile << "This weeks winning numbers\n";
			for (int i = 0; i < 7; i++) {
				randomNumberFile << randNums[i] << "\n";
			}
			randomNumberFile.close();
			//for testing purposes
			//cout << rand1 << " " << rand2 << " " << rand3 << " " << rand4 << " " << rand5 << " " << rand6 << " " << rand7 << endl;

			//displaying the users money
			cout << "Money: ";
			cout << money << endl;

			ofstream playerNumberFile;
			playerNumberFile.open("PlayerNumbers.txt", ios::out | ios::trunc);

			leave = false;//resetting the flag
			if (i == 1) {
				while (true) {
					cout << "Would you like to use the same numbers ?(y/n)";
					cin >> sameNums;
					if (sameNums == "y" || sameNums == "n") {
						break;
					}
					else
					{
						cout << "Must enter y or n";
					}
				}
			}
			if (sameNums == "n") {
				userNums = get_user_numbers();
			}
			//playerNumberFile.close();

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
		sameNums = "n";
	}//end of play again loop
	cout << "Thanks for playing!!!!";
}

/*
* This method displays the games title with rules and a description
*/
void display_title() {
	//title
	cout << "Welcome to lottery101" << endl;
	cout << "This is a lottery mimic game. You start the game by entering 7 numbers" << endl;
	cout << "and then these 7 numbers are checked with 7 computer-generated numbers." << endl;
	cout << "If any of these numbers match then you may lose or win money depending on how many numbers mathed.\n" << endl;
	cout << "---------------------------Rules------------------------------------" << endl;
	cout << "1. Can enter repeat numbers and numbers must be between 1 - 50" << endl;
	cout << "2. Have to enter Numbers can not enter any other characters" << endl;
	cout << "3. Start game with 50$" << endl;
	cout << "4. Each play costs 5$\n" << endl;
	cout << "--------------------Number match rules------------------------------" << endl;
	cout << "No numbers mathed lose 5$" << endl;
	cout << "1 number matched no money lost" << endl;
	cout << "2 numbers matched no money lost but please try again" << endl;
	cout << "3 numbers matched win a free play" << endl;
	cout << "4 numbers matched win 20$" << endl;
	cout << "5 numbers matched win 1000$" << endl;
	cout << "6 numbers matched win 100,000 " << endl;
	cout << "7 numbers matched win 70,000,000" << endl;
	cout << "brought to you by Ethan and Hunter" << endl << endl;
}

/*
* This method is getting the numbers from the user and putting them into an array
*/
vector<int> get_user_numbers() {
	vector<int> userNums(7);
	bool checked = true;
	int tempNum = 0;
	int count = 0;
	while (count < userNums.size()) {
		cout << "\nEnter number ";
		cout << count + 1 << endl; 
		cout << "Number musr be between 1 - 50" << endl;
		cin >> tempNum;
		if (tempNum > 50 || tempNum < 1 || cin.fail())
		{
			cout << "Invalid try again\n";
			checked = false;
			//clearing the input when invalid
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			for (int c = 0; c < 7; c++) {
				if (tempNum == userNums[c]) {
					cout << "Number already entered" << endl;
					checked = false;
					break;
				}
			}
		}

		if (checked) {
			userNums[count] = tempNum;
			count++;
		}
		checked = true;

			//playerNumberFile << num1 << "\n";
			//leave = true; //flag to see if the number inputed is valid
		
	}
}

vector<int> generate_rand_nums() {
	int randTemp;
	int counter = 0;
	bool safe = true;
	vector<int> randNums(7);
	//creating 7 random numbers
	int elapsed_seconds = time(nullptr);
	srand(elapsed_seconds);
	//for loop for generating the 7 random numebrs
	while (counter < randNums.size()) {
		randTemp = rand() % 50;
		randTemp = randTemp + 1;

		for (int i = 0; i < 7; i++) {
			if (randTemp == randNums[i]) {
				safe = false;
				break;
			}
		}

		if (safe) {
			randNums[counter] = randTemp;
			counter++;
		}
		else {
			safe = true;
		}
	}
	return randNums;
}