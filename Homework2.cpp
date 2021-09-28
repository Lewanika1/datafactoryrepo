#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;;;;

// Creating an enum
	enum menu {
	GREETING = 1,
	WEATHER = 2,
	GAME = 3
};

// Function declarations
void menu();
int main()
{
	// Declaring variables
	string greet;
	time_t rawtime;
	string time_str;
	string name;
	int hour, min, choice;

rawtime = time (&rawtime);
time_str = ctime (&rawtime);

// Convert string to integer
hour = atoi(time_str.substr(11, 2).c_str());
min = atoi(time_str.substr(14, 2).c_str());

// Displaying the header
cout << "+-------------------------------------------------------+" << endl;
cout << "| Computer Science and Engineering |" << endl;
cout << "| CSCE 1030 - Computer Science I |" << endl;
cout << "| Obidi Lewanika  Obidilewanika@unt.edu |" << endl;
cout << "+-------------------------------------------------------+" << endl;

// Getting input entered by the user
cout << "Please enter your full name:";
getline(cin, name);

/*  while loop continues to execute
* until the user enters an invalid choice or the choise is 4
*/
while (true) {
	menu();
	cout << "------->";
	//getting the choice  entered by the user
	cin >> choice;

	//Based on the user choice the corresponding case will be executed
	switch (choice) {
	case GREETING: {
		if (hour <= 11 && min <= 59) {
			greet = "morning";
		}
	else if ((hour >= 12) && (hour >= 17 && min <= 59)) {
		greet = "afternoon";
		cout << "hello" << endl;
	}
	else if ((hour >= 18) && (hour >= 23 && min <= 59)) {
		greet = "evening";
	}

	cout << time_str << endl;
	cout << "Good " << greet << ", " << name << ", I hope you're having a nice day!" << endl;
	continue;
}
	case WEATHER: {
		int temp = rand() % (96) + 10;
		int random = rand() % (1) + 1;
		string mesg;

		if (random == 1) {
		   mesg = "sunny";
	
		else if (random == 2) {
		   mesg = "rainy";
		}

		cout << "Today's forecast high of " << temp << " degrees and " << mesg << endl;

		continue;
	}
	case GAME: {
		int randNum, guess, cnt = 0;
		randNum = rand() % (10) + 1;
		cout << "You have 3 chances to guess my number from 1 to 10:" << endl;
		while (cnt < 3) {

			cout << "Guess #" << (cnt + 1) << ":";
			cin >> guess;
			if (randNum == guess) {
				cout << "Correct in " << cnt << " guesses! Nice job!!" << endl;
				break;
			}
			else if (guess < randNum) {
				cout << "Your guess (" << guess << ") is too low! Guess a higher number." << endl;
			}
			else {
				cout << "Your guess (" << guess << ") is too high! Guess a lower number." << endl;
}
			cnt++;
			}
			if (cnt == 3)
				cout << "Sorry, my number was " << randNum << "!" << endl;

			continue;
			}
			case 4: {
			   break;
			}
			default: {
				cout << "Invalid selection (" << choice << "). Enter option 1 - 4" << endl;
				break;
			}
			}
			break;
		}
		cout << "\nThank you for using the Personal Concierge*App." << endl;

		return 0;
}

// This function will display the menu
void menu()
{
	cout << "+--------------------- M E N U -----------------------+" << endl;
	cout << "| 1. Display Personal Greeting |" << endl;
	cout << "| 2. Display Today's Weather Forcast |" << endl;
	cout << "| 3. Play a Guessing Game |" << endl;
	cout << "| 4. Exit |" << endl;
	cout << "+-----------------------------------------------------+" << endl;
}
