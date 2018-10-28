#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib> //exit(0)

using namespace std;

int main() {

	double colonial_baseprice, colonial_sqft, colonialPricePerSqft; // Colonial model variables for base price and sqft, and price per squarefoot variable used for calculation.
	double split_baseprice, split_sqft, splitPricePerSqft; // Split-Entry variables for base price and sqft, and price per squarefoot variable used for calculation.
	double singlestry_baseprice, singlestry_sqft, singlestryPricePerSqft; // Single-Story variables for base price and sqft, and price per squarefoot variable used for calculation.

	cout << fixed << setprecision(2); // output total to two decimal places

/* Input prompt for Colonial Model accepting two values */

	cout << "Enter price and square feet for colonial model: ";
	cin >> colonial_baseprice >> colonial_sqft;

/* Error handling for colonial to terminate program for input equaling 0 or negative number or a string. */

	if (cin.fail() || colonial_baseprice <= 0 || colonial_sqft <= 0) {
		cout << "Invalid Input!" << endl;
		exit(0);
	} 

/* Input prompt for Split-Entry Model accepting two values */

	cout << "Enter price and square feet for split-entry model: ";
	cin >> split_baseprice >> split_sqft;

/* Error handling for split entry to terminate program for input equaling 0 or negative number or a string. */

	if (cin.fail() || split_baseprice <= 0 || split_sqft <= 0) {
		cout << "Invalid Input!" << endl;
		exit(0);
	} 

/* Input prompt for Single Story Model accepting two values */

	cout << "Enter price and square feet for single-story model: ";
	cin >> singlestry_baseprice >> singlestry_sqft;

/* Error handling for single story to terminate program for input equaling 0 or negative number or a string. */

	if (cin.fail() || singlestry_sqft <= 0 || singlestry_baseprice <= 0 ) {
		cout << "Invalid Input!" << endl;
		exit(0);
	} 
	
/* Conditional if no error occurs and inputs are valid */

	else { 

		colonialPricePerSqft = colonial_baseprice / colonial_sqft; // Calculation for price per squarefoot for colonial
		splitPricePerSqft = split_baseprice / split_sqft; // Calculation for price per squarefoot for split-entry
		singlestryPricePerSqft = singlestry_baseprice / singlestry_sqft; // Calculation for price per squarefoot for single-story


		/* 
			Conditional Statements for outputing minimum price per sqft: 

				1. If colonial is equal to split - output colonial and split-entry
				2. If colonial is equal to single - output colonial and single-story
				3. If split is equal to single - output split-entry and single-story
				4. If split is less than single and less than colonial - output split-entry
				5. If single is less than split and less than colonial - output single-story
				6. If colonial is less than single and less than split - output colonial

		*/


		if (colonialPricePerSqft == splitPricePerSqft) {
			cout << "Colonial and split-entry have same minimum price per square foot" << endl;
			cout << "Price per square foot $" << colonialPricePerSqft << endl;
		}
		else if (colonialPricePerSqft == singlestryPricePerSqft) {
			cout << "Colonial and single-story have same minimum price per square foot" << endl;
			cout << "Price per square foot $" << colonialPricePerSqft << endl;
		}
		else if (splitPricePerSqft == singlestryPricePerSqft) {
			cout << "Split-entry and single-story have same minimum price per square foot" << endl;
			cout << "Price per square foot $" << splitPricePerSqft << endl;
		} 
		else if (splitPricePerSqft < singlestryPricePerSqft && splitPricePerSqft < colonialPricePerSqft) {

			cout << "Split-entry has minimum price per square foot" << endl;
			cout << "Price per square foot $" << splitPricePerSqft << endl;

		}
		else if (singlestryPricePerSqft < splitPricePerSqft && singlestryPricePerSqft < colonialPricePerSqft) {

			cout << "Single-story has minimum price per square foot" << endl;
			cout << "Price per square foot $" << singlestryPricePerSqft << endl;

		}
		else if (colonialPricePerSqft < singlestryPricePerSqft && colonialPricePerSqft < splitPricePerSqft) {

			cout << "Colonial has minimum price per square foot" << endl;
			cout << "Price per square foot $" << colonialPricePerSqft << endl;

		}
		
	}
	return 0;
}