#include <iostream>

using namespace std;

int main() {

	int base, exp;
	int i = 0;
	int result = 1;

	cout << "Enter a base: ";
	cin >> base;

	cout << "Enter exponent ";
	cin >> exp;

	while (i < exp) {
		result = result * base;
		i++;
	}

cout << base << "^" << exp << " = " << result << endl;

	return 0;
}