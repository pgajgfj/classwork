#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    
    Array arr(5);
    arr.fillArray();
    arr.displayArray();
    arr.sortArray();
    arr.displayArray();
    cout << "Min Value: " << arr.findMin() << endl;
    cout << "Max Value: " << arr.findMax() << endl;

    // Example usage of String class
    String str1;
    String str2(100);
    str1.inputString();
    str1.outputString();
    str2.outputString();
    cout << "Number of String objects created: " << String::getCount() << endl;

}
