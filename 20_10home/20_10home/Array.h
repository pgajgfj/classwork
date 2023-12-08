#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
class Array {
private:
    int* data; 
    int size; 

public:

    Array(int initialSize = 10) : size(initialSize) {
        data = new int[size];
    }


    Array(const Array& other) : size(other.size) {
        data = new int[size];
        copy(other.data, other.data + size, data);
    }


    ~Array() {
        delete[] data;
    }


    void fillArray() {
        for (int i = 0; i < size; ++i) {
            cout << "Enter value for element " << i << ": ";
            cin >> data[i];
        }
    }

   
    void displayArray() {
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    
    void resizeArray(int newSize) {
        int* newData = new int[newSize];
        copy(data, data + min(size, newSize), newData);
        delete[] data;
        data = newData;
        size = newSize;
    }

    
    void sortArray() {
        sort(data, data + size);
    }

    
    int findMin() {
        return *min_element(data, data + size);
    }

    
    int findMax() {
        return *max_element(data, data + size);
    }
};

