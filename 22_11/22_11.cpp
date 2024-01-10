#include <iostream>
#include <fstream>

using namespace std;

enum GameCategory {
    ACTION,
    STRATEGY,
    RPG,
    SPORT,
    SIMULATION
};

class Game {
private:
    char name[50];
    GameCategory category;
    int popularity;

public:
    Game() {}
    
    Game(const char* n, GameCategory cat, int pop) : category(cat), popularity(pop) {
        strncpy_s(name, sizeof(name), n, _TRUNCATE);
    }

    void display() const {
        cout << "Name: " << name << ", Category: " << category << ", Popularity: " << popularity << endl;
    }

    friend class GameService;
};

class GameService {
public:
    void viewAllGames(const char* filename) {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        Game game;
        while (file.read(reinterpret_cast<char*>(&game), sizeof(Game))) {
            game.display();
        }

        file.close();
    }

    void addGame(const char* filename, const Game& game) {
        ofstream file(filename, ios::binary | ios::app);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        file.write(reinterpret_cast<const char*>(&game), sizeof(Game));

        file.close();
    }

    Game* searchGameByName(const char* filename, const char* gameName) {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return nullptr;
        }

        Game game;
        while (file.read(reinterpret_cast<char*>(&game), sizeof(Game))) {
            if (strcmp(game.name, gameName) == 0) {
                file.close();
                return new Game(game);
            }
        }

        file.close();
        return nullptr;
    }

    void searchGamesByCategory(const char* filename, GameCategory category) {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        Game game;
        while (file.read(reinterpret_cast<char*>(&game), sizeof(Game))) {
            if (game.category == category) {
                game.display();
            }
        }

        file.close();
    }

    void editGame(const char* filename, int gameNumber, const Game& newGame) {
        fstream file(filename, ios::binary | ios::in | ios::out);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        file.seekp(gameNumber * sizeof(Game), ios::beg);
        file.write(reinterpret_cast<const char*>(&newGame), sizeof(Game));

        file.close();
    }

    
};

int main() {
    GameService gameService;

    
    Game game1("Game1", ACTION, 100);
    Game game2("Game2", STRATEGY, 150);

    gameService.addGame("games.bin", game1);
    gameService.addGame("games.bin", game2);

    cout << "All games:" << endl;
    gameService.viewAllGames("games.bin");

    const char* searchName = "Game2";
    cout << "\nSearching for game by name '" << searchName << "':" << endl;
    Game* foundGame = gameService.searchGameByName("games.bin", searchName);
    if (foundGame) {
        foundGame->display();
        delete foundGame;
    }
    else {
        cout << "Game not found." << endl;
    }

    Game newGame("UpdatedGame", SPORT, 200);
    cout << "\nEditing game at position 0:" << endl;
    gameService.editGame("games.bin", 0, newGame);

    cout << "\nAll games after editing:" << endl;
    gameService.viewAllGames("games.bin");

    cout << "\nGames in the SPORT category:" << endl;
    gameService.searchGamesByCategory("games.bin", SPORT);

    return 0;
}