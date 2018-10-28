#include <iostream>

using namespace std;

char letterGrade(int);

int main() {

	int numGrade;
	char result;

	cout << "Enter score: " << endl;
	cin >> numGrade;

	result = letterGrade(numGrade);

	cout << "Result is: " << result << endl;


	return 0;
}

char letterGrade(int n) {
	switch (n / 10) {
		case 10: 
		case 9:
			return 'A';

		case 8: 
			return 'B';

		case 7: 
			return 'C';

		case 6: 
			return 'D';

		case 5: 
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			return 'F';

		default: 
			return 'I';
	}
}

