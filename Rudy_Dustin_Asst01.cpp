#include <iostream>
#include <string>

using namespace std;

int main(){

string nineCs; 
string twoCs;
string twoPluses;
string fourteenPluses;

nineCs = "CCCCCCCCC";
twoPluses = "++";
twoCs = "CC";
fourteenPluses = "++++++++++++++";

cout << nineCs << "      " << twoPluses << "              " << twoPluses << endl;
cout << twoCs << "             " << twoPluses << "              " << twoPluses << endl;
cout << twoCs << "          " << nineCs << "       " << nineCs << endl;
cout << twoCs << "          " << nineCs << "       " << nineCs << endl;
cout << twoCs << "             " << twoPluses << "              " << twoPluses << endl;
cout << nineCs << "      " << twoPluses << "              " << twoPluses << endl;


return 0;
}