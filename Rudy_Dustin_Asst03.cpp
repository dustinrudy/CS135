#include <iostream>

using namespace std;


// * Coin Constants 

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

// * Bill Constants

const int HUNDRED = 100;
const int TWENTY = 20;
const int TEN = 10;
const int FIVE = 5;
const int ONE = 1;




int main(){

// * Declared each variable with the appropriate DataTypes // 

double amountOwed, amountPaid;
int change, change2;
double changeDouble;




// * Prompts for collecting data for inputs in terminal //

cout << "Enter the amount owed: ";
cin >> amountOwed;

cout << "Enter the amount paid: ";
cin >> amountPaid;

cout << endl;


// * Calculation of change  //

changeDouble = amountPaid - amountOwed;

change = amountPaid - amountOwed;
change2 = (changeDouble - change) * 100;


// * Outputting variables to test and see happens with calculations at each point and step
cout << "Output of the change as int:  " << change << endl;
cout << "Output of the change as double:  " << changeDouble << endl;
cout << "Output of change2: " << change2 << endl; 
cout << change << endl;
cout << change2 << endl;

cout << endl;



// * Outputting the results in terminal //

cout << "Bills" << endl;
cout << "Amount of 100s = " << change / HUNDRED << endl;
change = change % HUNDRED;
cout << "Amount of 20s = " << change / TWENTY << endl;
change = change % TWENTY;
cout << "Amount of 10s = " << change / TEN << endl;
change = change % TEN;
cout << "Amount of 5s = " << change / FIVE << endl; 
change = change % FIVE;
cout << "Amount of 1s = " << change / ONE << endl;
change = change % ONE; 
cout << endl;


cout << "Coins" << endl;
cout << "Amount of quarters = " << change2 / QUARTER << endl; 
change2 = change2 % QUARTER;
cout << "Amount of dimes = " << change2 / DIME << endl;
change2 = change2 % DIME; 
cout << "Amount of nickels = " << change2 / NICKEL << endl; 
change2 = change2 % NICKEL;
cout << "Amount of pennies = " << change2 / PENNY << endl;
change2 = change2 % PENNY; 
cout << endl;



return 0;
}
