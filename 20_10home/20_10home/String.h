#pragma once
#include "Array.h"
class String {
private:
    char* str; // Pointer to dynamic array of characters
    static int count; // Static variable to keep track of the number of String objects

public:
    
    String() : str(new char[80]) {
        count++;
    }

    
    String(int size) : str(new char[size]) {
        count++;
    }

   
    String(const char* input) : str(new char[strlen(input) + 1]) {
        strcpy(str, input);
        count++;
    }

    
    ~String() {
        delete[] str;
        count--;
    }

    
    void inputString() {
        cout << "Enter a string: ";
        cin.ignore();
        cin.getline(str, 80);
    }

    
    void outputString() {
        cout << "String: " << str << endl;
    }

    
    static int getCount() {
        return count;
    }
    int String::count = 0;
};


