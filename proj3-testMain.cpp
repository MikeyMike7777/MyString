/* File: proj3-testMain.cpp
 * Author: Michael Mathews
 * Course: CSI 1440
 * Assignment: Project 3
 * Due Date: 9/17/21
 * Date Modified: 9/12/21
 *      - file and code created
 * Date Modified: 9/17/21
 *      - file and code finished
*/

#include "proj3-MyString.h"
#include <sstream>

using namespace std;

int main() {
    stringstream ss;
    string word;

    MyString str;
    str = "Welcome";
    MyString(str2) = "Greetings";

    // test assignment operator
    cout << "Testing Assignment operator" << endl;
    cout << str2 << endl;
    str2 = str;
    cout << str2 << endl << endl;

    //test copy constructor
    cout << "Testing Copy Constructor" << endl;
    MyString str3 = str2;
    cout << str3 << ' ' << str2 << endl << endl;

    //test equivalence relational
    cout << "Testing Equivalence Relational Operator" << endl;
    if (str == str2){
        cout << "Strings are equivalent" << endl;
    }
    else {
        cout << "Strings are not equal" << endl;
    }

    str2 = "Hello";

    if (str == str2){
        cout << "Strings are equivalent" << endl << endl;
    }
    else {
        cout << "Strings are not equivalent" << endl << endl;
    }

    // test array operator
    cout << "Testing array operator" << endl;
    cout << str[1] << endl;
    cout << str2[2]<< endl;
    cout << str[4] << endl << endl;

    // test overloaded addition
    cout << "Testing Overloaded Addition Operator" << endl;
    str3 = str + str2;
    cout << str3 << endl << endl;

    // test length
    cout << "Testing Length function" << endl;
    cout << str.length() << endl << endl;

    // test getline
    cout << "Testing getline function: " << endl;
    ss << "cool";
    getline(ss, word);
    cout << word << endl << endl;

    //Destructors called
    return 0;
}
