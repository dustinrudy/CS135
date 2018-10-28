#include <iostream>
#include <fstream>

using namespace std;


const int COURSES_AMOUNT = 5; // Rows for all arrays;
const int MAX_CAPACITY = 10; // Columns for students array;
const char Y = 'Y'; // The constant character decision for Yes;
const char N = 'N'; // The constant character decision for No;


///////// --------- Function Prototypes -------- //////////

void populateArray(ifstream&, string courses[], int amountEnrolled[], int capacities[], string students[][MAX_CAPACITY]);
string formatCourseName(string str);
string formatName(string str);
string searchForStudent(string nameToFind, int amountEnrolled[], string courses[], string students[][MAX_CAPACITY]);


int main() {

	string courses[COURSES_AMOUNT]; // courses array containing 5 courses;
	int amountEnrolled[COURSES_AMOUNT]; // int array containing how many students enrolled;
	int capacities[COURSES_AMOUNT]; // int array containing fixed values for each classes max capacity;
	string students[COURSES_AMOUNT][MAX_CAPACITY]; // students array containing 5 rows with 10 columns;
	ifstream inFile; // txt file object;
	char decision; // input decision for continuing; 


	populateArray(inFile, courses, amountEnrolled, capacities, students); // calling populateArray to grab information

	decision = Y;

	do {

		string studentName;
		string courseName;

		cout << "Enter student name: ";
		cin >> studentName;

		studentName = formatName(studentName);
		courseName = searchForStudent(studentName, amountEnrolled, courses, students);

		cout << "courseName: " << courseName << endl;

		if (courseName == "") {

			cout << studentName << " is not enrolled in any class" << endl;

		} else {

			cout << studentName << " is enrolled in " << courseName << endl;

		}

		cout << endl;
		cout << "Do you wish to continue? (Y/N): ";
		cin >> decision;

		decision = toupper(decision);

	} while(decision == Y);



	return 0;
}

void populateArray(ifstream&, string courses[], int amountEnrolled[], int capacities[], string students[][MAX_CAPACITY]) {

	ifstream inFile;
	string inputFile;

	cout << "Enter filename: ";
	cin >> inputFile;

	inFile.open(inputFile);

	while(inFile.fail()) {

			cin.clear();
			cin.ignore(100, '\n');
			inFile.clear();
			inFile.ignore(100, '\n');

			cerr << "File not found" << endl;

			populateArray(inFile, courses, amountEnrolled, capacities, students);

			return;
			
	};

	for(int i = 0; i < COURSES_AMOUNT; i++) {

		amountEnrolled[i] = 0;
		inFile >> courses[i]; 
		inFile >> capacities[i];

		courses[i] = formatCourseName(courses[i]);

	}

	string name; 
	string course; 


	while(!inFile.eof()) {

		int i = 0;

		inFile >> name;

		name = formatName(name);

		inFile >> course;

		course = formatCourseName(course);

		for(i = 0; i < COURSES_AMOUNT; i++) {

			if(courses[i] == course && amountEnrolled[i] != capacities[i]) {

				students[i][amountEnrolled[i]] = name;
				amountEnrolled[i]++;

				cout << "Names: " << name << " " << courses[i] << " " << amountEnrolled[i] << endl;

			}
		}

	}


	inFile.close();
	return;

}


string searchForStudent(string nameToFind, int amountEnrolled[], string courses[], string students[][MAX_CAPACITY]) {

	string arr;
	string str;

	for(int i = 0; i < COURSES_AMOUNT; i++) {
		for (int j = 0; j < amountEnrolled[i]; j++) {

			arr = students[i][j];

			cout << "arr:   " << arr << endl;

			if(arr == nameToFind) {

				str = courses[i];

				cout << "str:   " << str << endl;

			} else {

				str = "";
	
			}
		}
	}
	return str;
}



string formatName(string str) {
	string tmp = str;

  tmp[0] = toupper(tmp[0]); //first character upper cased

  //the rest of the characters are lower cased
  for (int i = 1; i < tmp.length(); i++)
    tmp[i] = tolower(tmp[i]);

  return tmp;
}


string formatCourseName(string str) {

	string tmp = str;

  tmp[0] = toupper(tmp[0]); //first character upper cased
  tmp[1] = toupper(tmp[1]); //second character upper cased

  //the rest of the characters are lower cased
  for (int i = 2; i < tmp.length(); i++)
    tmp[i] = tolower(tmp[i]);

  return tmp;

}