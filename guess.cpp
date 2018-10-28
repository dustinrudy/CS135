#include <iostream>
#include <cstdlib> // rand() random function
#include <ctime> // use a different seed for random number generator

using namespace std;

const int MAX_TRIES = 4;

int main() {

		int correct, guess;
		int tries = 0;

		srand(time(NULL)); // generates a new random number each time program executes

		correct = (rand() % 10) + 1; // random number between 1 and 10

		cout << "Correct = " << correct << endl;

	// cout << rand() << endl << rand() << endl << rand() << endl; // testing rand()

		guess = 0;

		while (guess != correct && tries < MAX_TRIES) { // keeps looping until guess will equal correct or until user guesses 4 times

			cout << "Try and guess the number: ";
			cin >> guess;

			tries++;
		}

		if (tries < MAX_TRIES) {

			cout << "You won!" << endl;
			cout << "It took you " << tries << " number of guesses" << endl;

		}

		else {

			cout << "You lost! Out of tries" << endl;

		}

	return 0;
}