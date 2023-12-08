
#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {
    
    Fraction fraction1, fraction2, result;

    cout << "Enter the first fraction:\n";
    fraction1.enterFraction();

    cout << "\nEnter the second fraction:\n";
    fraction2.enterFraction();

    
    result = fraction1.add(fraction2);
    cout << "\nSum: ";---
    result.displayFraction();

    
    result = fraction1.subtract(fraction2);
    cout << "\nDifference: ";
    result.displayFraction();

    
    result = fraction1.multiply(fraction2);
    cout << "\nProduct: ";
    result.displayFraction();

    
    result = fraction1.divide(fraction2);
    cout << "\nQuotient: ";
    result.displayFraction();

    return 0;
}