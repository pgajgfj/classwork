#pragma once
#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cerr << "Error: Denominator cannot be zero." << endl;
            exit(1);
        }
        simplify(); 
    }

    
    void simplify() {
        int gcd = getGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    
    int getGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    
    Fraction operator+(const Fraction& other) const {
        int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    
    Fraction operator-(const Fraction& other) const {
        int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

   
    Fraction operator*(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cerr << "Error: Division by zero." << endl;
            exit(1);
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    
    void display() const {
        cout << numerator << "/" << denominator;
    }
};
