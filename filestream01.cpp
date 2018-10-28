#include <iostream>
#include <fstream> // filestream  variables

using namespace std;

int main() {

	int n;
	int i = 0;
	int sum = 0;
	
	ifstream inFile;

	inFile.open("input.txt");

	inFile >> n;



	while (!inFile.eof()) {

		if (inFile.fail()) {

			inFile.clear();
			inFile.ignore(100, '\n');

		}

		else {

			sum = sum + n;
			i++;


		}

		inFile >> n;

	}

	cout << "Sum = " << sum << endl;
	cout << "Count = " << i << endl;
	cout << "Avg = " << double(sum) / i << endl;

return 0;

}
