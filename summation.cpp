#include <iostream>
using namespace std;

int main() {

	int start, end;
	int sum = 0;
	int tmp;
	int amount = 0;
	double avg;

		cout << "Enter start index: ";
		cin >> start;

		cout << endl;

		cout << "Enter end index: ";
		cin >> end;

		cout << endl;

		if (start <= end) {
			amount = end - start;

			while (start < end) {

			cout << "Enter a number: ";
			cin >> tmp;

			sum += tmp;
			start++;

			}
			avg = double(sum) / amount;
			cout << "Avg = " << avg << endl;
		} 
		else {
			cout << "Avg = 0.0" << endl;
		}

	return 0;

}