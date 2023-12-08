#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Contact
{
private:
    char* fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

public:
    
    Contact() : fullName(nullptr) {}

    
    Contact(const char* name, const string& home, const string& work, const string& mobile, const string& additional)
        : homePhone(home), workPhone(work), mobilePhone(mobile), additionalInfo(additional) {

       
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }

    
    ~Contact() {
       
        delete[] fullName;
    }

    
    const char* getFullName() const { return fullName; }
    const string& getHomePhone() const { return homePhone; }
    const string& getWorkPhone() const { return workPhone; }
    const string& getMobilePhone() const { return mobilePhone; }
    const string& getAdditionalInfo() const { return additionalInfo; }

    
    void setFullName(const char* name) {
        delete[] fullName;
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }

    void setHomePhone(const string& phone) { homePhone = phone; }
    void setWorkPhone(const string& phone) { workPhone = phone; }
    void setMobilePhone(const string& phone) { mobilePhone = phone; }
    void setAdditionalInfo(const string& info) { additionalInfo = info; }
};


