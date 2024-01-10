#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Game
{
enum Category {
        ACTION,
        RPG,
        SPORTS,
        STRATEGY
};
private:
    static const int MAX_NAME_SIZE = 50;
    char name[MAX_NAME_SIZE];
    Category category;
    int popularity;

public:
    Game() : category(Category::ACTION), popularity(0) {}

    Game(const char* n, Category cat, int pop) : category(cat), popularity(pop) {
        strncpy(name, n, MAX_NAME_SIZE - 1);
        name[MAX_NAME_SIZE - 1] = '\0';
    }

    void display() const {
        cout << "Name: " << name << ", Category: " << category << ", Popularity: " << popularity << endl;
    }

    const char* getName() const {
        return name;
    }

    Category getCategory() const {
        return category;
    }

    int getPopularity() const {
        return popularity;
    }

    friend ostream& operator<<(ostream& os, const Game& game);
    friend istream& operator>>(istream& is, Game& game);
};
