#ifndef FOREIGN_PASSPORT_H
#define FOREIGN_PASSPORT_H
using namespace std;
#include "Passport.h"
#include <string>

namespace ForeignPassport {
    class ForeignPassport : public Passport::Passport {
    private:
        string visaInfo;

    public:
        
        ForeignPassport(const string& name, const string& number, const string& visa);
        void display() const override;
    };
}

#endif 