#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

void printBook(const Book& book) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Publisher: " << book.publisher << endl;
    cout << "Genre: " << book.genre << endl;
    cout << "-------------------------" << endl;
}

void printAllBooks(Book* library, int size) {
    for (int i = 0; i < size; ++i) {
        printBook(library[i]);
    }
}

void searchByAuthor(Book* library, int size, const string& author) {
    for (int i = 0; i < size; ++i) {
        if (library[i].author == author) {
            printBook(library[i]);
        }
    }
}

void searchByTitle(Book* library, int size, const string& title) {
    for (int i = 0; i < size; ++i) {
        if (library[i].title == title) {
            printBook(library[i]);
            return;
        }
    }
    cout << "Book with title \"" << title << "\" not found." << endl;
}

void sortByTitle(Book* library, int size) {
    sort(library, library + size, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
}

void sortByAuthor(Book* library, int size) {
    sort(library, library + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
}

void sortByPublisher(Book* library, int size) {
    sort(library, library + size, [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
}

void addBook(Book*& library, int& size, const Book& newBook) {
    Book* newLibrary = new Book[size + 1];
    for (int i = 0; i < size; ++i) {
        newLibrary[i] = library[i];
    }
    newLibrary[size] = newBook;
    ++size;
    delete[] library;
    library = newLibrary;
}

void removeBookByTitle(Book*& library, int& size, const string& title) {
    for (int i = 0; i < size; ++i) {
        if (library[i].title == title) {
            library[i] = library[size - 1];
            --size;
            Book* newLibrary = new Book[size];
            for (int j = 0; j < size; ++j) {
                newLibrary[j] = library[j];
            }
            delete[] library;
            library = newLibrary;
            cout << "Book with title \"" << title << "\" has been removed." << endl;
            return;
        }
    }
    cout << "Book with title \"" << title << "\" not found." << endl;
}

int main() {
    Book* library = new Book[10];
    int librarySize = 0;

    addBook(library, librarySize, { "Book1", "Author1", "Publisher1", "Genre1" });
    addBook(library, librarySize, { "Book2", "Author2", "Publisher2", "Genre2" });
    addBook(library, librarySize, { "Book3", "Author3", "Publisher3", "Genre3" });

    cout << "All Books:" << endl;
    printAllBooks(library, librarySize);

    cout << "Books by Author2:" << endl;
    searchByAuthor(library, librarySize, "Author2");

    cout << "Search for Book3:" << endl;
    searchByTitle(library, librarySize, "Book3");

    sortByTitle(library, librarySize);
    cout << "Books after sorting by title:" << endl;
    printAllBooks(library, librarySize);

    sortByAuthor(library, librarySize);
    cout << "Books after sorting by author:" << endl;
    printAllBooks(library, librarySize);

    sortByPublisher(library, librarySize);
    cout << "Books after sorting by publisher:" << endl;
    printAllBooks(library, librarySize);

    addBook(library, librarySize, { "NewBook", "NewAuthor", "NewPublisher", "NewGenre" });
    cout << "Books after adding a new book:" << endl;
    printAllBooks(library, librarySize);

    removeBookByTitle(library, librarySize, "Book2");
    cout << "Books after removing Book2:" << endl;
    printAllBooks(library, librarySize);

    delete[] library;

    return 0;
}
