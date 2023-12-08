#include <iostream>
#include <string>

using namespace std;

// Завдання 1. Структура «Пральна машинка»
struct WashingMachine {
    string brand;
    string color;
    float width;
    float length;
    float height;
    int power;
    int spinSpeed;
    int heatingTemperature;
};

// Завдання 2. Структура «Праска»
struct Iron {
    string brand;
    string model;
    string color;
    int minTemperature;
    int maxTemperature;
    bool steamFunction;
    int power;
};

// Завдання 3. Структура «Бойлер»
struct Boiler {
    string brand;
    string color;
    int power;
    float capacity;
    int heatingTemperature;
};

int main() {
    // Створення екземпляру «Пральна машинка» та виведення інформації
    WashingMachine washingMachine;
    washingMachine.brand = "Samsung";
    washingMachine.color = "White";
    washingMachine.width = 60.0;
    washingMachine.length = 80.0;
    washingMachine.height = 100.0;
    washingMachine.power = 1200;
    washingMachine.spinSpeed = 1000;
    washingMachine.heatingTemperature = 40;

    cout << "Washing Machine Details:" << endl;
    cout << "Brand: " << washingMachine.brand << endl;
    cout << "Color: " << washingMachine.color << endl;
    cout << "Dimensions (W x L x H): " << washingMachine.width << " x " << washingMachine.length << " x " << washingMachine.height << " cm" << endl;
    cout << "Power: " << washingMachine.power << " W" << endl;
    cout << "Spin Speed: " << washingMachine.spinSpeed << " RPM" << endl;
    cout << "Heating Temperature: " << washingMachine.heatingTemperature << " °C" << endl;
    cout << endl;

    // Створення екземпляру «Праска» та виведення інформації
    Iron iron;
    iron.brand = "Philips";
    iron.model = "PerfectCare Elite";
    iron.color = "Blue";
    iron.minTemperature = 100;
    iron.maxTemperature = 200;
    iron.steamFunction = true;
    iron.power = 2400;

    cout << "Iron Details:" << endl;
    cout << "Brand: " << iron.brand << endl;
    cout << "Model: " << iron.model << endl;
    cout << "Color: " << iron.color << endl;
    cout << "Temperature Range: " << iron.minTemperature << " - " << iron.maxTemperature << " °C" << endl;
    cout << "Steam Function: " << (iron.steamFunction ? "Yes" : "No") << endl;
    cout << "Power: " << iron.power << " W" << endl;
    cout << endl;

    // Створення екземпляру «Бойлер» та виведення інформації
    Boiler boiler;
    boiler.brand = "Bosch";
    boiler.color = "Silver";
    boiler.power = 2000;
    boiler.capacity = 50.0;
    boiler.heatingTemperature = 60;

    cout << "Boiler Details:" << endl;
    cout << "Brand: " << boiler.brand << endl;
    cout << "Color: " << boiler.color << endl;
    cout << "Power: " << boiler.power << " W" << endl;
    cout << "Capacity: " << boiler.capacity << " liters" << endl;
    cout << "Heating Temperature: " << boiler.heatingTemperature << " °C" << endl;

    return 0;
}
