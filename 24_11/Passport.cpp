#include "Passport.h"
#include <iostream>
using namespace std;
using namespace Passport;

Passport::Passport::Passport(const std::string& name, const std::string& number)
    : fullName(name), passportNumber(number) {}

void Passport::Passport::display() const {
    cout << "Passport Information:\n";
    cout << "Full Name: " << fullName << "\n";
    cout << "Passport Number: " << passportNumber << "\n";
}