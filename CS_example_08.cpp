#include <iostream> 
#include <iomanip> 

using namespace std;

int main() {

	int counter = 0; 
	int n = 0;
	int tmp;
	double avg;

	cout << "Enter number of steps: ";
	cin >> n;

	while (counter < n) {
		cout << "Enter a number: ";
		cin >> tmp;
		counter = counter + tmp;
		n++;
	}

	avg = double(counter) / n;
	cout << avg << endl;

	return 0;	
}