
#include <iostream>
#include "Fraction.h"


using namespace std;


int main()
{
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);

    Fraction sum = frac1 + frac2;
    Fraction difference = frac1 - frac2;
    Fraction product = frac1 * frac2;
    Fraction quotient = frac1 / frac2;

    cout << "Fraction 1: ";
    frac1.display();
    cout << endl;

    cout << "Fraction 2: ";
    frac2.display();
    cout << endl;

    cout << "Sum: ";
    sum.display();
    cout << endl;

    cout << "Difference: ";
    difference.display();
    cout << endl;

    cout << "Product: ";
    product.display();
    cout << endl;

    cout << "Quotient: ";
    quotient.display();
    cout << endl;

}

