#include <iostream>

using namespace std;

int main() {

	int grade;

	cout << endl;

	cout << "Enter Grade from 0 to 10: ";
	cin >> grade;

	cout << endl;

	if (grade <= 5)
		cout << "F" << endl;
	else if (grade > 8) 
		cout << "A" << endl;
	else if (grade > 7)
		cout << "B" << endl;
	else if (grade > 6)
		cout << "C" << endl;
	else if (grade > 5)
		cout << "D" << endl;

	return 0;
}