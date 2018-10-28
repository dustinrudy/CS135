#include <iostream>
#include <cstdlib> // rand() random function
#include <ctime> // use a different seed for random number generator

using namespace std;


int main() {

		int i;

		for (i = 0; i < 10; i++) {

			if (i == 4) {
				cout << "Almost done" << endl;
			} 
			else {
				cout << "Message " << i + 1 << endl;
			}
		}

		cout << "End of sequence" << endl;
		

	return 0;
}