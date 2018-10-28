#include <iostream>
using namespace std;

const double INCHES_TO_CM = 2.5401;
const double LBS_TO_KG = 2.202;

int main(){

double heightInInches1, weightInLbs1, heightInInches2, weightInLbs2;
double heightInCm1, weightInKg1, heightInCm2, weightInKg2;

cout << "Enter height in inches person 1: ";
cin >> heightInInches1;

cout << "Enter weight in Lbs person 1: ";
cin >> weightInLbs1;

heightInCm1 = heightInInches1 * INCHES_TO_CM;
weightInKg1 = weightInLbs1 / LBS_TO_KG;

cout << "Height in cm of person 1: " << heightInCm1 << endl;
cout << "Weight in kg of person 1: " << weightInKg1 << endl;

cout << "Enter height in inches person 2: ";
cin >> heightInInches2;

cout << "Enter weight in Lbs person 2: ";
cin >> weightInLbs2;

heightInCm2 = heightInInches2 * INCHES_TO_CM;
weightInKg2 = weightInLbs2 / LBS_TO_KG;

cout << "Height in cm of person 2: " << heightInCm2 << endl;
cout << "Weight in kg of person 2: " << weightInKg2 << endl;

	return 0;
}