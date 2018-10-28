#include <iostream>
#include <iomanip>
using namespace std;

const double TAX = 0.0825; 

int main(){

	double item1, item2;
	double total;
	double totalAfterTaxes; 

	cout << fixed << setprecision(2); // output total to two decimal places

	cout << "Enter price of item 1: " << endl; // prompt user for input for price of item 1.
	cin >> item1; // assigns input to varibable item1.

	cout << "Enter price of item 2: " << endl; // prompt user for input for price of item 2.
	cin >> item2; // assigns input to varibable item2.

	cout << endl;

	total = item1 + item2;
	totalAfterTaxes = total * (1 + TAX);


	// Output costs of item 1 and 2

	cout << left << setw(20) << "Item 1";
	cout << "$";
	cout << right << setw(10) << item1;
	cout << endl;

	cout << left << setw(20) << "Item 2";
	cout << "$";
	cout << right << setw(10) << item2;
	cout << endl;


	// Output total cost

	cout << left << setw(20) << "Total";
	cout << "$";
	cout << right << setw(10) << total;
	cout << endl;

	// Output tax amount

	cout << left << setw(20) << "Taxes";
	cout << "$";
	cout << right << setw(10) << total * TAX;
	cout << endl;

	// Output total after tax

	cout << left << setw(20) << "Final Cost";
	cout << "$";
	cout << right << setw(10) << totalAfterTaxes;
	cout << endl;

	cout << endl;


return 0;
}