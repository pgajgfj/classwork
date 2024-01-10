#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "Game.h"
using namespace std;
class GameDatabase {
private:
    static const char* FILENAME;

public:
    static void viewAllGames() {
        ifstream file(FILENAME, ios::binary);
        if (!file) {
            cerr << "Error opening file." << endl;
            return;
        }

        Game game;
        while (file.read(reinterpret_cast<char*>(&game), sizeof(Game))) {
            game.display();
        }

        file.close();
    }

    static void addGame(const Game& newGame) {
        ofstream file(FILENAME, ios::binary | ios::app);
        if (!file) {
            cerr << "Error opening file." << endl;
            return;
        }

        file.write(reinterpret_cast<const char*>(&newGame), sizeof(Game));

        file.close();
    }

    static void searchByName(const char* name) {
        ifstream file(FILENAME, ios::binary);
        if (!file) {
            cerr << "Error opening file." << endl;
            return;
        }

        Game game;
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&game), sizeof(Game))) {
            if (strcmp(game.getName(), name) == 0) {
                game.display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Game with name '" << name << "' not found." << endl;
        }

        file.close();
    }

    static void searchByCategory(Category category) {
        ifstream file(FILENAME, ios::binary);
        if (!file) {
            cerr << "Error opening file." << endl;
            return;
        }

        Game game;
        while (file.read(reinterpret_cast<char*>(&game), sizeof(Game))) {
            if (game.getCategory() == category) {
                game.display();
            }
        }

        file.close();
    }

    static void editGame(int index, const Game& editedGame) {
        fstream file(FILENAME, ios::binary | ios::in | ios::out);
        if (!file) {
            cerr << "Error opening file." << endl;
            return;
        }

        file.seekp(index * sizeof(Game), ios::beg);
        file.write(reinterpret_cast<const char*>(&editedGame), sizeof(Game));

        file.close();
    }

    // Додатковий метод для видалення гри за іменем чи номером
    static void removeGame(const char* name) {
        ifstream infile(FILENAME, ios::binary);
        if (!infile) {
            cerr << "Error opening file." << endl;
            return;
        }

        ofstream outfile("temp.dat", ios::binary);
        Game game;

        while (infile.read(reinterpret_cast<char*>(&game), sizeof(Game))) {
            if (strcmp(game.getName(), name) != 0) {
                outfile.write(reinterpret_cast<const char*>(&game), sizeof(Game));
            }
        }

        infile.close();
        outfile.close();

        // Перейменовуємо тимчасовий файл
        remove(FILENAME);
        rename("temp.dat", FILENAME);
    }

    static void clearDatabase() {
        ofstream file(FILENAME, ios::trunc);
        if (!file) {
            cerr << "Error opening file." << endl;
            return;
        }

        file.close();
    }
};

