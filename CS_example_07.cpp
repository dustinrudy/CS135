#include <iostream>

using namespace std;

int main() {

	int month;

		cout << "Enter month number: ";
		cin >> month;


		if (month == 1) {
			cout << "Jan" << endl;
		}
		else 
			if (month == 2) {
				cout << "Feb" << endl;
			}
			else 
				if (month == 3) {
					cout << "Mar" << endl;
				}
				else 
					if (month == 4){
						cout << "Apr" << endl;
					}
					else 
						cout << "Invalid month index" << endl;





return 0;
}