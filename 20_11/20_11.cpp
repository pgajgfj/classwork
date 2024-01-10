


#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class ExistLoginException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: User with this login already exists!";
    }
};

class WrongPasswordLengthException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Password length should be at least 8 characters!";
    }
};

class FormatPasswordException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Password should contain at least one digit, one uppercase letter, one lowercase letter, and one special character.";
    }
};

class InvalidLoginException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid login!";
    }
};

class InvalidPasswordException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid password!";
    }
};

class User_Account {
private:
    string password;
    string login;

public:
    User_Account(const string& login, const string& password) : login(login), password(password) {}

    const string& getLogin() const {
        return login;
    }

    const string& getPassword() const {
        return password;
    }
};

class SocialNetwork {
private:
    vector<User_Account> accounts;

public:
    void registerUser(const string& login, const string& password) {
        try {
            for (const auto& user : accounts) {
                if (user.getLogin() == login) {
                    throw ExistLoginException();
                }
            }

            if (password.length() < 8) {
                throw WrongPasswordLengthException();
            }

            bool hasDigit = false, hasUpper = false, hasLower = false, hasSpecial = false;
            for (char ch : password) {
                if (isdigit(ch)) {
                    hasDigit = true;
                }
                else if (isupper(ch)) {
                    hasUpper = true;
                }
                else if (islower(ch)) {
                    hasLower = true;
                }
                else if (ispunct(ch)) {
                    hasSpecial = true;
                }
            }

            if (!(hasDigit && hasUpper && hasLower && hasSpecial)) {
                throw FormatPasswordException();
            }

            accounts.emplace_back(login, password);
            cout << "Registration successful!\n";
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }

    void login(const string& login, const string& password) {
        try {
            bool userFound = false;
            for (const auto& user : accounts) {
                if (user.getLogin() == login) {
                    userFound = true;
                    if (user.getPassword() == password) {
                        cout << "Login successful!\n";
                    }
                    else {
                        throw InvalidPasswordException();
                    }
                }
            }

            if (!userFound) {
                throw InvalidLoginException();
            }
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }
};

int main() {
    SocialNetwork socialNetwork;

    socialNetwork.registerUser("user1", "StrongPassword123!");
    socialNetwork.login("user1", "StrongPassword123!");

    socialNetwork.registerUser("user2", "weak");
    socialNetwork.registerUser("user3", "NoDigitsOrSpecialChars");
    socialNetwork.registerUser("user1", "DuplicateUser"); 

    socialNetwork.login("nonexistent_user", "password");
    socialNetwork.login("user1", "IncorrectPassword");

    return 0;
}