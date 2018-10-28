#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

///////// --------- Function Prototypes -------- //////////

void getInfo(int& age, bool& paid, int& sessions);
double yearlyCost(bool senior, bool paid);
double trainingCost (int sessions);
void outputMembershipCost (double membershipCost, double costTraining);

///////// ---- Constants for discounts, rates, and character decisions -------- //////////

const double THIRTY_PERCENT_DISC = 0.30; // 30% discount constant if user is 63 and older.
const double FIFTEEN_PERCENT_DISC = 0.15; // 15% discount constant if user paid the annual membership in full.
const double TWENTY_PERCENT_DISC = 0.20; // 20% discount constant if user has more than 5 training sessions per month.
const double MEMBERSHIP_ANNUAL_RATE = 23.00 * 12; // constant for annual rate membership cost before discounts. 
const double TRAINING_SESSION_RATE = 8.00; // the constant for price training session per month.
const char Y = 'Y'; // The constant character decision for Yes;
const char N = 'N'; // The constant character decision for No;


int main() {

	int age, sessions; // variables for user input age, sessions;
	bool paid; // based on char decision of paying annual will return true or false
	bool isSenior; // based on if the age variable is >= 63 or not will return true or false
	bool charInvalid = false; // default bool value used in while loop error checking
	double annualcost, trainingcost; // variables to assign output of functions
	char decision; // variable for decision to continue program

	decision = Y; // when starting program: decision variable will be yes so while loop will execute;

	while (decision == Y) {

		cout << fixed << setprecision(2); // output total to two decimal places


		getInfo(age, paid, sessions); // takes in user prompts

		if (age >= 63) { // If age is equal to 63 and older then bool val is true
			isSenior = true;
		} else { // If less than 63 bool val is false
			isSenior = false;
		};

		annualcost = yearlyCost(isSenior, paid); // Assigning annualcost variable and calling function while passing bool vals into function for whether not they are a senior and whether they paid annual membership
		trainingcost = trainingCost(sessions); // Assigning trainingcost variable and calling function while passing int sessions into function

		cout << endl;

		outputMembershipCost(annualcost, trainingcost); // Function call and outputs results to the screen.



/* Prompts for Decision to Continue  */

		cout << "Continue? (Y/N): ";
		cin >> decision; 
		decision = toupper(decision);

		while (!charInvalid) {
			decision = toupper(decision);

			if (decision == Y) { // If decision is yes then will jump back to start of program and reprompt;

					decision = Y;
					charInvalid = true;

				} else if (decision == N) { // If decision is no then program terminates;

					decision = N;
					charInvalid = true;

				} else { // If input error occurs reprompt until valid input is given;

					cin.clear();
					cin.ignore(100, '\n');
					cout << "Invalid input! (Enter Y or N)" << endl;
					cout << "Continue (Y/N): ";
					cin >> decision;
					toupper(decision);
					charInvalid = false;

				}
		}
	}

	return 0;
}

///////// --------- Functions -------- //////////

void getInfo(int& age, bool& paid, int& sessions) {

	char isPaid;
	bool isInvalid = false;

	cout << "Welcome to some random fitness club!" << endl;

	cout << "Please enter your age: ";
	cin >> age;

	/* Error checking while loop: 

	If age is negative or string keep prompting. 

	Else assign input to age */

	while(age <= 0 || cin.fail()) {

		cin.clear();
		cin.ignore(100, '\n');

		cout << "Invalid Input! (Enter a positive number)" << endl;
		cout << "Please enter your age: ";
		cin >> age;

	};

	cout << "Will you pay the entire year membership in full? (Y/N): ";
	cin >> isPaid; 

	/* Error checking while loop: 
	
	Returns bool value 

	If 'N' 
	paid = false 

	If 'Y' paid = true 

	Anything else remprompt for correct input

	*/

	while(!isInvalid) {

		isPaid = toupper(isPaid);

		if (toupper(isPaid) == 'Y') {

			paid = true;
			isInvalid = true;

		} else if (toupper(isPaid) == 'N') {
			paid = false;
			isInvalid = true;

		} else {
			cout << "Invalid Input! (Please Enter Y or N)" << endl;
			cout << "Will you pay the entire year membership in full? (Y/N): ";
			cin >> isPaid;
		}
	};


	cout << "Please enter training sessions per month: ";
	cin >> sessions;

	/* Error checking while loop  
	
	Returns int sessions

	If sessions is negative then reprompt

	Else assign sessions variable to user input


	*/

	while(sessions < 0 || cin.fail()) {

		cin.clear();
		cin.ignore(100, '\n');

		cout << "Invalid Input! (Enter a positive number)" << endl;

		cout << "Please enter training sessions per month: ";
		cin >> sessions;

	};

	return;
}

double yearlyCost(bool senior, bool paid) {

	double cost;

	if (paid) { // If user marked yes for paying annual membership: Apply 15% discount to cost;
		cost = MEMBERSHIP_ANNUAL_RATE - (MEMBERSHIP_ANNUAL_RATE * FIFTEEN_PERCENT_DISC);
	} else if (senior) { // If user is a senior: Apply 30% discount to cost
		cost = MEMBERSHIP_ANNUAL_RATE - (MEMBERSHIP_ANNUAL_RATE * THIRTY_PERCENT_DISC);
	} else if (senior && paid) { // If user marked yes for paying annual membership and is a senior: Apply 45% discount to cost;
		cost = MEMBERSHIP_ANNUAL_RATE - ((MEMBERSHIP_ANNUAL_RATE * THIRTY_PERCENT_DISC) + (MEMBERSHIP_ANNUAL_RATE * FIFTEEN_PERCENT_DISC));
	} else { // If user marked no for paying annual membership and is not a senior: No discount is applied return base cost;
	}

	return cost;
}

double trainingCost(int sessions) {

	double traincost;
	double discount;

	if (sessions > 5) { // If number sessions larger than 5 per month: Apply 20% discount along to the training session rate;

		discount = ((sessions * TRAINING_SESSION_RATE) * 12) * TWENTY_PERCENT_DISC;
		traincost = ((sessions * TRAINING_SESSION_RATE) * 12) - discount;

	} else { // If number of sessions is 5 or less per month: No discount applied;

		traincost = (sessions * TRAINING_SESSION_RATE) * 12;
	}

	return traincost;
}

void outputMembershipCost(double membershipCost, double costTraining) {

	cout << left << setfill('.') << setw(50) << "Membership Cost";
	cout << "$";
	cout << right << setfill(' ') << setw(10) << membershipCost;
	cout << endl;

	cout << left << setfill('.') << setw(50) << "Training Cost";
	cout << "$";
	cout << right << setfill(' ') << setw(10) << costTraining;
	cout << endl;

	cout << left << setfill('.') << setw(50) << "Yearly Cost";
	cout << "$";
	cout << right << setfill(' ') << setw(10) << membershipCost + costTraining;
	cout << endl;

	return;
}


