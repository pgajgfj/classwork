#include <iostream>
#include <string>

using namespace std;

class Passport {
protected:
    string fullName;
    string idNumber;
    string dateOfBirth;

public:
    Passport(const string& fullName, const string& idNumber, const string& dateOfBirth)
        : fullName(fullName), idNumber(idNumber), dateOfBirth(dateOfBirth) {}

    void displayInfo() const {
        cout << "Passport Information:" << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "ID Number: " << idNumber << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
    }
};

class ForeignPassport : public Passport {
private:
    string passportNumber;
    string visaInfo;

public:
    ForeignPassport(const string& fullName, const string& idNumber, const string& dateOfBirth,
        const string& passportNumber, const string& visaInfo)
        : Passport(fullName, idNumber, dateOfBirth), passportNumber(passportNumber), visaInfo(visaInfo) {}

    void displayForeignPassportInfo() const {
        displayInfo();  
        cout << "Passport Number: " << passportNumber << endl;
        cout << "Visa Information: " << visaInfo << endl;
    }
};

int main() {
    
    

    Passport ukrainePassport("John Doe", "123456789", "01/01/1990");
    ukrainePassport.displayInfo();

    cout << endl;

    ForeignPassport foreignPassport("John Doe", "123456789", "01/01/1990", "AB123456", "USA, Canada");
    foreignPassport.displayForeignPassportInfo();

    return 0;
}
