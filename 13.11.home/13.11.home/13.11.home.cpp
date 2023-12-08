#include <iostream>
#include <string>

using namespace std;


class Animal {
protected:
    string name;
    size_t age;

public:
    Animal(const string& _name, size_t _age) : name(_name), age(_age) {}

    virtual void sound() const = 0;
    virtual void type() const = 0;
    virtual void show() const = 0;


    const string& getName() const {
        return name;
    }

    size_t getAge() const {
        return age;
    }

    void setName(const string& _name) {
        name = _name;
    }

    void setAge(size_t _age) {
        age = _age;
    }
};


class Dog : public Animal {
public:
    Dog(const string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        cout << "Woof" << endl;
    }

    void type() const override {
        cout << "Dog" << endl;
    }

    void show() const override {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Type: ";
        type();
        cout << "Sound: ";
        sound();
        cout << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        cout << "Meow" << endl;
    }

    void type() const override {
        cout << "Cat" << endl;
    }

    void show() const override {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Type: ";
        type();
        cout << "Sound: ";
        sound();
        cout << endl;
    }
};

class Parrot : public Animal {
public:
    Parrot(const string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        cout << "Squawk" << endl;
    }

    void type() const override {
        cout << "Parrot" << endl;
    }

    void show() const override {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Type: ";
        type();
        cout << "Sound: ";
        sound();
        cout << endl;
    }
};

class Hamster : public Animal {
public:
    Hamster(const string& _name, size_t _age) : Animal(_name, _age) {}

    void sound() const override {
        cout << "Squeak" << endl;
    }

    void type() const override {
        cout << "Hamster" << endl;
    }

    void show() const override {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Type: ";
        type();
        cout << "Sound: ";
        sound();
        cout << endl;
    }
};


class HomeZoo {
private:
    Animal** zoo;
    size_t size;

public:
    HomeZoo() : zoo(nullptr), size(0) {}

    ~HomeZoo() {
        removeAllAnimals();
    }

    void addAnimal(Animal* newAnimal) {
        Animal** newZoo = new Animal * [size + 1];
        for (size_t i = 0; i < size; ++i) {
            newZoo[i] = zoo[i];
        }
        newZoo[size] = newAnimal;
        delete[] zoo;
        zoo = newZoo;
        ++size;
    }

    void removeAnimal(size_t index) {
        if (index >= size) {
            cerr << "Invalid index" << endl;
            return;
        }

        delete zoo[index];

        for (size_t i = index; i < size - 1; ++i) {
            zoo[i] = zoo[i + 1];
        }

        --size;
    }

    void removeAllAnimals() {
        for (size_t i = 0; i < size; ++i) {
            delete zoo[i];
        }
        delete[] zoo;
        zoo = nullptr;
        size = 0;
    }

    void displayAllAnimals() const {
        for (size_t i = 0; i < size; ++i) {
            zoo[i]->show();
        }
    }
};

int main() {
    
    Dog myDog("Buddy", 3);
    Cat myCat("Whiskers", 2);
    Parrot myParrot("Polly", 5);
    Hamster myHamster("Nibbles", 1);

    
    HomeZoo myHomeZoo;

    
    myHomeZoo.addAnimal(&myDog);
    myHomeZoo.addAnimal(&myCat);
    myHomeZoo.addAnimal(&myParrot);
    myHomeZoo.addAnimal(&myHamster);

   
    cout << "All Animals in the Zoo:" << endl;
    myHomeZoo.displayAllAnimals();

    
    myHomeZoo.removeAnimal(1);

   
    cout << "\nRemaining Animals in the Zoo:" << endl;
    myHomeZoo.displayAllAnimals();

    
    myHomeZoo.removeAllAnimals();

    return 0;
}
