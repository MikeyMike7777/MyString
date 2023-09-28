/* File: proj3-MyString.h
 * Author: Michael Mathews
 * Course: CSI 1440
 * Assignment: Project 3
 * Due Date: 9/17/21
 * Date Modified: 9/12/21
 *      - file and code created
 * Date Modified: 9/17/21
 *      - file and code finished
*/

#ifndef PROJECT_3_PROJ3_MYSTRING_H
#define PROJECT_3_PROJ3_MYSTRING_H

#include <iostream>

using namespace std;

class MyString {
    public:
        //Default Constructor
        MyString();
        //Changes const char* to MyString
        MyString(const char *);
        //Destructor
        ~MyString();
        //Copy Constructor
        MyString(const MyString &);
        //Overloaded Assignment operator
        MyString &operator=(const MyString &);
        //Overloaded operator ==
        bool operator==(const MyString &) const;
        //Overloaded operator []
        char &operator[](int);
        //Overloaded operator +=
        //Combines two MyStrings into first MyString
        //resizes array if necessary
        void operator+=(const MyString &);
        //Overloaded operator +
        //Creates a new MyString and returns combination of two MyStrings
        MyString operator+(const MyString &) const;

        /**
        -  getline
        -
        -  This function reads in a set of characters and put them in an array
        -  Also resizes array if necessary
        -
        -  Parameters:
        -    istream&
        -    char: delimit '\n'
        -
        -  Output:
        -    return: none
        */
        void getline(istream&, char delimit);

        /**
        -  length
        -
        -  Returns the length of a MyString
        -
        -  Parameters:
        -    none
        -
        -  Output:
        -    return: int
        */
        int length( ) const;

        /**
        -  overload operator <<
        -
        -  This function overloads the operator <<
        -
        -  Parameters:
        -    ostream&
        -    MyString&
        -
        -  Output:
        -    return: ostream&
        */
        friend ostream& operator<< (ostream&, MyString&);
    private:
        int size;
        int capacity;
        char *data;
};




#endif //PROJECT_3_PROJ3_MYSTRING_H
