/* File: proj3-MyString.cpp
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

using namespace std;

//Default Constructor
MyString::MyString() {
    this->size = 0;
    this->capacity = 10;
    this->data = new char[this->capacity];
    /** this->data[this->capacity] = '\0'; */
}

// Constructor with an initialization character string
MyString::MyString(const char *str) {
    /** delete [] this; */

    //set size
    this->size = 0;
    this->capacity = 10;
    while (str[this->size] != '\0') {
        this->size++;
    }

    //set capacity
    while (this->size > this->capacity) {
        this->capacity *= 2;
    }

    //allocate memory
    this->data = new char[this->capacity];

    //copy data
    for (int i = 0; i < this->size; i++) {
        this->data[i] = str[i];
    }

    //add null terminator
    this->data[this->size] = '\0';
}

// Destructor
MyString::~MyString() {
    //Delete data and free allocated memory
    delete [] this->data;
    cout << "Destructor called" << endl;
}

// Copy constructor
MyString::MyString(const MyString &str) {
    //copy my string members, cap, size, and allocate memory
    this->size = str.size;
    this->capacity = str.capacity;
    this->data = new char[this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = str.data[i];
    }
    this->data[this->size] = '\0';
}

// Overloaded assignment operator, make a copy of MyString object
MyString& MyString::operator=(const MyString &str) {
    //Make sure not self assigning
    if (this != &str) {
        //copy size, capacity, and data members to allocated memory
        this->size = str.size;
        this->capacity = str.capacity;
        this->data = new char[this->capacity];
        for (int i = 0; i < this->size; i++) {
            this->data[i] = str.data[i];
        }
        this->data[this->size] = '\0';
    }
    return *this;
}

//Overloaded == operator
bool MyString::operator==(const MyString &str) const {
    //to return if it equals
    bool flag = true;
    //check sizes
    if (this->size == str.size) {
        //check data members
        for (int i = 0; i < this->size; i++) {
            //if not equal set to false
            if (this->data[i] != str.data[i]) {
                flag = false;
            }
        }
    }
    else {
        flag = false;
    }
    //Return false if sizes aren't equal or one data member is not equal
    //Return true if two MyStrings are equal
    return flag;
}

char& MyString::operator[](int i){
    return this->data[i];
}

void MyString::operator+=(const MyString &str) {
    char* temp;
    int j = 0;
    //increase capacity if needed
    while ((this->size + str.size) > this->capacity) {
        temp = new char[capacity*2];
        for (int i = 0; i < this->size; i++) {
            temp[i] = this->data[i];
        }
        delete [] this->data;
        this->data = temp;
    }
    //add strings
    for (int i = this->size; str.data[j] != '\0'; i++) {
        this->data[i] = str.data[j];
        j++;
    }
    //create new size
    this->size += str.size;
    //set last character to \0
    this->data[this->size] = '\0';
}

/**
    char* temp;
    int j = 0;
    //increase capacity if needed
    while ((this->size + str.size) > this->capacity) {
        this->capacity *= 2;
    } */

//operator + overload
MyString MyString::operator+(const MyString &str) const {
    MyString strTot;
    int j = 0;

    //free memory allocated by constructor
    delete [] strTot.data;

    //set size and capacity for new string
    strTot.size = (str.size + this->size);
    strTot.capacity = this->capacity;

    //increase capacity if needed
    while (strTot.capacity < strTot.size) {
        strTot.capacity *= 2;
    }

    //allocate memory for new MyString
    strTot.data = new char[strTot.capacity];

    //fill array with first string
    for (int i = 0; i < this->size; i++) {
        strTot.data[i] = this->data[i];
    }
    //fill string with second string
    for (int i = this->size; str.data[j] != '\0'; i++) {
        strTot.data[i] = str.data[j];
        j++;
    }

    //Make last character null terminator
    strTot.data[strTot.size] = '\0';

    //return MyString
    return strTot;
}

//getline function
void MyString::getline(istream &in, char delimit = '\n') {
    char *tempArray;
    char temp;
    int i = 0;

    //get first letter
    in.get(temp);
    //while not newline or end of file get a data member and increase size
    while (temp != delimit and !in.eof()) {
        this->data[i] = temp;
        this->size++;
        //if size bigger than cap, double cap
        if (this->size > this->capacity) {
            tempArray = new char[capacity * 2];
            for (int i = 0; i < this->size; i++) {
                tempArray[i] = this->data[i];
            }
            //free memory
            delete[] this->data;
            this->data = tempArray;
        }
        // get new variable
        in.get(temp);
    }
    //decrease size if cap more than 4 times bigger
    if (this->size < (this->capacity/4)) {
        tempArray = new char[capacity / 2];
        for (int j = 0; j < this->size; j++) {
            tempArray[j] = this->data[j];
        }
        //free memory
        delete[] this->data;
        this->data = tempArray;
    }
    //set last character to null character
    this->data[this->size] = '\0';
}

int MyString::length( ) const {
    //give back implicit size
    return this->size;
}

//overload << operator
ostream& operator<< (ostream &out, MyString &str) {
    for (int i = 0; i < str.size; i++) {
        out << str.data[i];
    }
    return out;
}