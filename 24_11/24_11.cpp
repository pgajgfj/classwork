#include <iostream>
#include "Passport.h"
#include "ForeignPassport.h"

int main() {
    Passport::Passport passport("Meow Doe", "342234359");
    passport.display();

    cout << "\n";

    ForeignPassport::ForeignPassport foreignPassport("Jane Doe", "987654321", "Schengen Visa");
    foreignPassport.display();

    return 0;
}