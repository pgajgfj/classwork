#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FuelType {
public:
    string name;
    double pricePerLiter;

    FuelType(const string& n, double price) : name(n), pricePerLiter(price) {}
};

class FuelStation {
private:
    vector<FuelType> fuelTypes;
    double earnings;

public:
    FuelStation() : earnings(0.0) {
        
        fuelTypes.emplace_back("Gasoline", 2.5);
        fuelTypes.emplace_back("Diesel", 2.0);
        fuelTypes.emplace_back("LPG", 1.8);
    }

    void refillFuel(const string& type, double liters) {
        for (auto& fuelType : fuelTypes) {
            if (fuelType.name == type) {
                double cost = liters * fuelType.pricePerLiter;
                earnings += cost;
                cout << "Refilled " << liters << " liters of " << type << " fuel. Cost: $" << cost << endl;
                return;
            }
        }

        cout << "Invalid fuel type." << endl;
    }

    void displayFuelTypes() const {
        cout << "Available fuel types and prices:" << endl;
        for (const auto& fuelType : fuelTypes) {
            cout << fuelType.name << ": $" << fuelType.pricePerLiter << " per liter" << endl;
        }
    }

    void changeFuelPrice(const string& type, double newPrice) {
        for (auto& fuelType : fuelTypes) {
            if (fuelType.name == type) {
                fuelType.pricePerLiter = newPrice;
                cout << "Changed price for " << type << " fuel to $" << newPrice << " per liter." << endl;
                return;
            }
        }

        cout << "Invalid fuel type." << endl;
    }

    void displayStatistics() const {
        cout << "Fuel station statistics:" << endl;
        cout << "Total earnings: $" << earnings << endl;
        for (const auto& fuelType : fuelTypes) {
            cout << "Sold " << fuelType.name << " fuel: " << earnings / fuelType.pricePerLiter << " liters"
                << " for $" << earnings << endl;
        }
    }
};

class CoffeeMachine {
private:
    double earnings;

public:
    CoffeeMachine() : earnings(0.0) {}

    void refillCoffee() {
        cout << "Coffee machine refilled." << endl;
    }

    void sellCoffee() {
        double price = 2.0;
        earnings += price;
        cout << "Coffee sold. Price: $" << price << endl;
    }

    void displayCoffeeStatistics() const {
        cout << "Coffee machine statistics:" << endl;
        cout << "Total earnings from coffee sales: $" << earnings << endl;
    }
};

int main() {
    FuelStation fuelStation;
    CoffeeMachine coffeeMachine;

    int mode;
    cout << "Enter mode (1 for admin, 2 for user): ";
    cin >> mode;

    if (mode == 1) { 
       
        fuelStation.refillFuel("Gasoline", 100.0);
        fuelStation.displayFuelTypes();
        fuelStation.changeFuelPrice("Diesel", 2.2);
        fuelStation.displayStatistics();

       
        coffeeMachine.refillCoffee();
        coffeeMachine.displayCoffeeStatistics();
    }
    else if (mode == 2) { // User mode
        
        fuelStation.refillFuel("Gasoline", 20.0);
        fuelStation.displayFuelTypes();

        coffeeMachine.sellCoffee();
        coffeeMachine.displayCoffeeStatistics();
    }
    else {
        cout << "Invalid mode." << endl;
    }

    return 0;
}
