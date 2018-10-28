#include <iostream>

using namespace std;

int main() {

		int iterations;
		int n, i;


		cout << "Enter amount of numbers to read: ";
		cin >> iterations;

		for (i = 0; i < iterations; i++) {
			cout << "Enter number " << i + 1 << ": ";
			cin >> n;

			while (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid number!!!" << endl << endl;
				cout << "Enter number " << i + 1 << ": ";
				cin >> n;
			}
		}


	return 0;
}