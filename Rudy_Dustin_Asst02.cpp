#include <iostream>

using namespace std;

int main(){

// * Declared each variable with the appropriate DataTypes // 

int capacity;
double mpg;
double percentage;
int distance;

// * Prompts for collecting data from user inputs in terminal //

cout << "Please enter amount of gallons fuel tank can hold: ";
cin >> capacity;

cout << "Please enter the vehicle mile per gallon: ";
cin >> mpg;

cout << "Please enter percentage of tank that contains gas: ";
cin >> percentage;

// * Calculation of distance before refuelling and assigning to "distance" variable //

distance = percentage * (mpg * capacity);


// * Outputting the result in terminal //

cout << "The vehicle can go " << distance << " miles before refilling";

return 0;
}