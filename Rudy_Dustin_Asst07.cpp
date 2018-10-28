#include <iostream>
#include <cmath>
#include <cstdlib> 

using namespace std;

int main() {

	int n, temp; // n is the variable for the number inputted and used for calculation and temp is the is the number for the output without it being calculated.
	int i = 0; // iterator variable for the do while loop
	int sum = 0; // the variable for the sum of each digit of the number
	int amountOfDigits; // the amount of digits in a given number, used for indexing.

	/* First prompt for entering number */

	cout << "Please enter a number: "; 
	cin >> n;
	temp = n;


/* Error handling for negative integers and random strings using while loop */

	while (n < 0 || cin.fail()) {

			cin.clear();
			cin.ignore(100, '\n');

		cout << "Please enter a number: ";
		cin >> n;
		temp = n;

	};

	amountOfDigits = int(log10(n)) + 1; // Calculation for extracting a single digit from the right.


/* Using do while loop determing the sum of digits and */

	do {

		if (i % 2) { // if the index number is odd then subtract
			sum = sum - n % 10;

			n = n / 10;


		} else { // if the index number is even then add
			sum = sum + n % 10;

			n = n / 10;

		}

		i++;

	} while (i < amountOfDigits); // do while loop until it reaches the end of the index {

		if (sum % 11 == 0) {  // If the sum is divisble by 11 output this statement

			cout << "Sum of digits is " << sum << endl;
			cout << sum << " is divisible by 11 therefore " << temp << " is divisible by 11" << endl;

		} else { // If the sum is not divisible by 11 output this statement

			cout << "Sum of digits is " << sum << endl;
			cout << sum << " is not divisible by 11 therefore " << temp << " is not divisible by 11" << endl;

		}
	return 0;
}



	
	