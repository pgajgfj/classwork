#include <iostream>

using namespace std;

class Circle {
private:
    double radius;

public:
    
    Circle(double r = 0) : radius(r) {}

    
    bool operator==(const Circle& other) const {
        return radius == other.radius;
    }

    
    bool operator>(const Circle& other) const {
        return 2 * 3.14 * radius > 2 * 3.14 * other.radius;
    }

    
    Circle& operator+=(double increment) {
        radius += increment;
        return *this;
    }

    Circle& operator-=(double decrement) {
        if (radius - decrement < 0) {
            cerr << "Error: Radius cannot be negative." << endl;
            exit(1);
        }
        radius -= decrement;
        return *this;
    }

    
    void display() const {
        cout << "Radius: " << radius << endl;
    }
};

class Airplane {
private:
    string type;
    int passengers;

public:
    
    Airplane(const string& t, int p) : type(t), passengers(p) {}

   
    bool operator==(const Airplane& other) const {
        return type == other.type;
    }

    
    Airplane& operator++() {
        ++passengers;
        return *this;
    }

    Airplane& operator--() {
        if (passengers <= 0) {
            cerr << "Error: Cannot have negative passengers." << endl;
            exit(1);
        }
        --passengers;
        return *this;
    }

    
    bool operator>(const Airplane& other) const {
        return passengers > other.passengers;
    }

    
    void display() const {
        cout << "Type: " << type << ", Passengers: " << passengers << endl;
    }
};

int main() {
   
    Circle c1(5);
    Circle c2(7);

    if (c1 == c2) {
        cout << "Circles are equal in radius." << endl;
    }
    else {
        cout << "Circles are not equal in radius." << endl;
    }

    if (c1 > c2) {
        cout << "Circle 1 has a greater circumference than Circle 2." << endl;
    }
    else {
        cout << "Circle 2 has a greater circumference than Circle 1." << endl;
    }

    c1 += 2;
    c1.display();  

    c2 -= 3;
    c2.display(); 

    
    Airplane a1("Boeing 747", 300);
    Airplane a2("Airbus A380", 500);

    if (a1 == a2) {
        cout << "Airplanes are of the same type." << endl;
    }
    else {
        cout << "Airplanes are not of the same type." << endl;
    }

    ++a1;
    a1.display();  

    --a2;
    a2.display();  

    if (a1 > a2) {
        cout << "Airplane 1 can accommodate more passengers than Airplane 2." << endl;
    }
    else {
        cout << "Airplane 2 can accommodate more passengers than Airplane 1." << endl;
    }

    return 0;
}