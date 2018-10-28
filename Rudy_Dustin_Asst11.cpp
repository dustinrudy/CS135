#include <iostream>
#include <fstream>

using namespace std;

const int COURSES_AMOUNT = 5;
const int MAX_CAPACITY = 10;
const char Y = 'Y'; // The constant character decision for Yes;
const char N = 'N'; // The constant character decision for No;


struct csCourse {

string courseName;
int amountEnrolled;
int capacity;
string students[MAX_CAPACITY];

};


void populateArrays (ifstream& inFile, csCourse courses[]);
string searchForStudent (string nameToFind, csCourse courses[]);
string formatName (string studentName);
string formatCourseName (string course);





int main () {

	csCourse courses[COURSES_AMOUNT];
	ifstream inFile;
	char decision;


	populateArrays(inFile, courses);

	decision = Y;

	do {

		string studentName;
		string courseName;

		cout << "Enter student name: ";
		cin >> studentName;

		studentName = formatName(studentName);
		courseName = searchForStudent(studentName, courses);

		if(courseName == "") {

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


void populateArrays(ifstream&, csCourse courses[]) {

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

			populateArrays(inFile, courses);

			return;
			
	};

	for(int i = 0; i < COURSES_AMOUNT; i++) {

		inFile >> courses[i].courseName; 
		inFile >> courses[i].capacity;

		courses[i].courseName = formatCourseName(courses[i].courseName);

		courses[i].amountEnrolled = 0;

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

			if(courses[i].courseName == course && courses[i].amountEnrolled != courses[i].capacity) {
				courses[i].students[courses[i].amountEnrolled] = name;  
				courses[i].amountEnrolled++;

				cout << "Names: " << name << " " << courses[i].courseName << " " << courses[i].amountEnrolled << endl;
			} 
		}

	}


	inFile.close();
	return;

}

string searchForStudent(string nameToFind, csCourse courses[]) {

	string str;
	string arr;

	for(int i = 0; i < COURSES_AMOUNT; i++) {
		for (int j = 0; j < courses[i].amountEnrolled; j++) {

			arr = courses[i].students[j];

			cout << "arr:   " << arr << endl;

			if(courses[i].students[j] == nameToFind) {

				str = courses[i].courseName;

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