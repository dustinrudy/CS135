#include <iostream>

using namespace std;

int main() {

	int n;
	int i = 0;

	cin >> n;

	while (!cin.eof()) {

		cout << "Number " << i + 1 << ": " << n << endl;
		i++;

		cin >> n;
	}

return 0;

}
