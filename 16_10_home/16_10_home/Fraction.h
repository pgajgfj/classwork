#pragma once
#include <iostream>
using namespace std;
class Fraction {
private:
    int numerator;   
    int denominator; 

public:
    // Constructor
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    
    void enterFraction() {
        cout << "Enter numerator: ";
        cin >> numerator;

        do {
            cout << "Enter non-zero denominator: ";
            cin >> denominator;
        } while (denominator == 0);
    }

    
    void displayFraction() const {
        cout << numerator << "/" << denominator;
    }

    
    Fraction add(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction subtract(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            cerr << "Error: Division by zero." << endl;
            return Fraction();
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
};
