#ifndef PASSPORT_H
#define PASSPORT_H

#include <string>

namespace PassportNamespace {

    class Passport {
    public:

        virtual void display() const;        
        Passport(const std::string& name, const std::string& number);

        
        void display() const; 
    protected:
        std::string passportNumber;
        std::string fullName;
    };

} 

#endif 