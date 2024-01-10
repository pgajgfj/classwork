#include "ForeignPassport.h"
#include <iostream>
using namespace ForeignPassportNamespace;
ForeignPassport::ForeignPassport(const std::string& name, const std::string& number, const std::string& visa)
    : Passport::Passport(name, number), visaInfo(visa) {
}

void ForeignPassport::display() const {
    Passport::display();
    std::cout << "Visa Information: " << visaInfo << "\n";
}