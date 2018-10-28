#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib> //exit(0)

using namespace std;

const double COST_PER_SQFT = 0.50; // the cost per square foot constant.
const double TAX_RATE = 0.0825; // the tax rate constant for calculating after tax.
const double TEN_DISCOUNT = 0.10;
const double TWENTY_DISCOUNT = 0.20;
const double THIRTY_DISCOUNT = 0.30;
const char Y = 'Y';
const char N = 'N';

int main() {

	double length1, length2, length3; // input variables for length of the 3 rooms
	double width1, width2, width3; // input variables for width of the 3 rooms
	double totalSqFt, cost, costAfterDiscount, tax, totalAfterTax; // variables for calculating cost
	char decision;
	bool isInvalid = false;

	cout << fixed << setprecision(2); // output total to two decimal places

	decision = Y;

	while (decision == Y) {
	cout << "Enter length and width of room 1: ";
	cin >> length1;
	cin >> width1;

	// Error Checking while loop 
		while (length1 < 0 || width1 < 0 || cin.fail()) {

			cin.clear();
			cin.ignore(100, '\n');

			cout << "Invalid input!" << endl;

			cout << "Enter length and width of room 1: ";
			cin >> length1;
			cin >> width1;
		};	

	cout << "Enter length and width of room 2: ";
	cin >> length2;
	cin >> width2;

// Error Checking while loop 

		while (length2 < 0 || width2 < 0 || cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input!" << endl;
			cout << "Enter length and width of room 2: ";
			cin >> length2;
			cin >> width2;
		};	

		cout << "Enter length and width of room 3: "; 
		cin >> length3;
		cin >> width3;

// Error Checking while loop 

	while (length3 < 0 || width3 < 0 || cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input!" << endl;
			cout << "Enter length and width of room 3: ";
			cin >> length3;
			cin >> width3;
			break;
		};	

	totalSqFt = (length1 * width1) + (length2 * width2) + (length3 * width3); // Calculation of total sqft of all 3 rooms combined
	cost = totalSqFt * COST_PER_SQFT; // Calculation of all 3 rooms with the 0.50 rate cost_per_sqft to obtain cost before discount



/* Outputting the total square feet of all 3 rooms */

	cout << left << setfill('.') << setw(20) << "Square Feet";
	cout << " ";
	cout << right << setfill(' ') << setw(10) << totalSqFt;
	cout << endl;

/* Outputting the total cost of all 3 rooms */

	cout << left << setfill('.') << setw(20) << "Cost";
	cout << "$";
	cout << right << setfill(' ') << setw(10) << cost;
	cout << endl;


/* 
		1. if else cases for calculation of discount based on cost 

		2. output of total after the discount 
*/

	if (cost >= 600.00) {
		cout << left << setfill('.') << setw(20) << "Discount";
		cout << " ";
		cout << right << setfill(' ') << setw(10) << "30.00%";
		cout << endl;

		costAfterDiscount = cost - (cost * THIRTY_DISCOUNT);

		cout << left << setfill('.') << setw(20) << "After discount";
		cout << "$";
		cout << right << setfill(' ') << setw(10) << costAfterDiscount;
		cout << endl;

	} else if (cost >= 400.00) { 

		cout << left << setfill('.') << setw(20) << "Discount";
		cout << " ";
		cout << right << setfill(' ') << setw(10) << "20.00%";
		cout << endl;

		costAfterDiscount = cost - (cost * TWENTY_DISCOUNT);

		cout << left << setfill('.') << setw(20) << "After discount";
		cout << "$";
		cout << right << setfill(' ') << setw(10) << costAfterDiscount;
		cout << endl;
	} else if (cost >= 200.00) {

		cout << left << setfill('.') << setw(20) << "Discount";
		cout << " ";
		cout << right << setfill(' ') << setw(10) << "10.00%";
		cout << endl;

		costAfterDiscount = cost - (cost * TEN_DISCOUNT);

		cout << left << setfill('.') << setw(20) << "After discount";
		cout << "$";
		cout << right << setfill(' ') << setw(10) << costAfterDiscount;
		cout << endl;
	} else {

		cout << left << setfill('.') << setw(20) << "Discount";
		cout << " ";
		cout << right << setfill(' ') << setw(10) << "0.00%";
		cout << endl;

		costAfterDiscount = cost;

		cout << left << setfill('.') << setw(20) << "After discount";
		cout << "$";
		cout << right << setfill(' ') << setw(10) << costAfterDiscount;
		cout << endl;
	}

	tax = costAfterDiscount * TAX_RATE; // Calculation for Tax


/* Outputting the tax amount */

	cout << left << setfill('.') << setw(20) << "Tax";
	cout << "$";
	cout << right << setfill(' ') << setw(10) << tax;
	cout << endl; 

	totalAfterTax = costAfterDiscount * (1 + TAX_RATE); // Calculation of adding the tax to the total cost


/* Outputting the total after taxes */
	
	cout << left << setfill('.') << setw(20) << "Total";
	cout << "$";
	cout << right << setfill(' ') << setw(10) << totalAfterTax;
	cout << endl; 


	cout << "Continue (Y/N): ";
	cin >> decision;
	decision = toupper(decision);

		// Error checking for continue prompt 
	
			while (!isInvalid) {
				if (decision == Y) {
					decision = Y;
					isInvalid = true;
				} else if (decision == N) {
					decision = N;
					isInvalid = true;
				} else {
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Invalid input!" << endl;
					cout << "Continue (Y/N): ";
					cin >> decision;
					toupper(decision);
					isInvalid = false;
				}
			}
}
	return 0;
} 

	