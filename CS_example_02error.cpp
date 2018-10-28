#include <iostream>
using namespace std;

const double INCHES_TO_CM = 2.54;
const double LBS_TO_KG = 2.2;

int main(){

double heightInInches, weightInLbs;
double heightInCm, weightInKg;

cout << "Enter height in inches: ";
cin >> heightInInches;

if (cin.fail())
	{

		cin.clear(); // resets input stream back to a working state
		cin.ignore(100, '\n'); // skip over next 100 characters or until it hits endl character

		cout << "Enter height in inches: ";
		cin >> heightInInches;
	}

cout << "Enter weight in Lbs: ";
cin >> weightInLbs;

if (cin.fail())
	{

		cin.clear(); // resets input stream back to a working state
		cin.ignore(100, '\n'); // skip over next 100 characters or until it hits endl character
		
		cout << "Enter weight in Lbs: ";
		cin >> weightInLbs;
	}


heightInCm = heightInInches * INCHES_TO_CM;
weightInKg = weightInLbs / LBS_TO_KG;

cout << "Height in cm " << heightInCm << endl;
cout << "Weight in kg " << weightInKg << endl;

	return 0;
}