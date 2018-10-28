#include <iostream>
using namespace std;

const double INCHES_TO_CM = 2.54;
const double LBS_TO_KG = 2.2;

int main(){

double heightInInches, weightInLbs;
double heightInCm, weightInKg;

cout << "Enter height in inches and weight in lbs: ";
cin >> heightInInches >> weightInLbs; 

heightInCm = heightInInches * INCHES_TO_CM;
weightInKg = weightInLbs / LBS_TO_KG;

cout << "Height in cm " << heightInCm << endl;
cout << "Weight in kg " << weightInKg << endl;

	return 0;
}