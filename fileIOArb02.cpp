#include <iostream>

using namespace std;

int main() {

	int n;
	int i = 0;
	int sum = 0;

	cin >> n;



	while (!cin.eof()) {

		if (cin.fail()) {

			cin.clear();
			cin.ignore(100, '\n');

		}

		else {

			sum = sum + n;
			i++;


		}

		cin >> n;

	}

	cout << "Sum = " << sum << endl;
	cout << "Count = " << i << endl;
	cout << "Avg = " << double(sum) / i << endl;

return 0;

}
