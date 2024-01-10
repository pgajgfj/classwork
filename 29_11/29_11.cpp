#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class Book {
private:
    string author;
    string name;
    int year;
    bool available;

public:
    Book(const string& author, const string& name, int year)
        : author(author), name(name), year(year), available(true) {}

    string getAuthor() const { return author; }
    string getName() const { return name; }
    int getYear() const { return year; }
    bool isAvailable() const { return available; }

    void markAsIssued() { available = false; }
    void markAsReturned() { available = true; }

    
    void setAuthor(const string& newAuthor) { author = newAuthor; }
    void setName(const string& newName) { name = newName; }
    void setYear(int newYear) { year = newYear; }
    void setAvailability(bool newAvailability) { available = newAvailability; }

    friend ostream& operator<<(ostream& os, const Book& book);
};

ostream& operator<<(ostream& os, const Book& book) {
    os << "Author: " << book.author << ", Name: " << book.name
        << ", Year: " << book.year << ", Available: " << (book.available ? "Yes" : "No");
    return os;
}

class Library {
private:
    list<Book> books;

public:
    void addBook(const Book& book) { books.push_back(book); }

    void displayAllBooks() const {
        for_each(books.begin(), books.end(), [](const Book& book) {
            cout << book << endl;
            });
    }

    Book* searchBook(const string& author, const string& name) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getAuthor() == author && book.getName() == name;
            });

        return (it != books.end()) ? &(*it) : nullptr;
    }

    void issueBook(Book& book) {
        if (book.isAvailable()) {
            book.markAsIssued();
            cout << "Book issued: " << book << endl;
        }
        else {
            cout << "Book is not available for issue." << endl;
        }
    }

    void returnBook(Book& book) {
        if (!book.isAvailable()) {
            book.markAsReturned();
            cout << "Book returned: " << book << endl;
        }
        else {
            cout << "Book is already in the library." << endl;
        }
    }

    void sortBooks() {
        books.sort([](const Book& a, const Book& b) {
            return (a.getAuthor() != b.getAuthor()) ? (a.getAuthor() < b.getAuthor())
            : (a.getName() < b.getName());
            });
    }

    void removeBook(const string& author, const string& name, int year) {
        books.remove_if([&](const Book& book) {
            return book.getAuthor() == author && book.getName() == name && book.getYear() == year;
            });
    }

    void removeBookByIndex(size_t index) {
        auto it = next(books.begin(), index);
        if (it != books.end()) {
            books.erase(it);
            cout << "Book removed successfully." << endl;
        }
        else {
            cout << "Invalid index." << endl;
        }
    }

    void editBook(const string& oldName, const string& oldAuthor, const string& newName,
        const string& newAuthor) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getName() == oldName && book.getAuthor() == oldAuthor;
            });

        if (it != books.end()) {
           
            it->setName(newName);
            it->setAuthor(newAuthor);
            cout << "Book edited successfully." << endl;
        }
        else {
            cout << "Book not found." << endl;
        }
    }
    void saveBooksToFile(const string& filename) const {
        ofstream outFile(filename);
        for (const auto& book : books) {
            outFile << book.getAuthor() << "," << book.getName() << "," << book.getYear() << ","
                << (book.isAvailable() ? "1" : "0") << "\n";
        }
        cout << "Books saved to file." << endl;
    }

    void loadBooksFromFile(const string& filename) {
        books.clear();
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            istringstream iss(line);
            string author, name;
            int year;
            bool available;

            if (getline(iss, author, ',') && getline(iss, name, ',') && (iss >> year) &&
                (iss.ignore(), iss >> available)) {
                Book book(author, name, year);
                if (!available) {
                    book.markAsIssued();
                }
                books.push_back(book);
            }
            else {
                cerr << "Error parsing line: " << line << endl;
            }
        }

        cout << "Books loaded from file." << endl;
    }
};

int main() {
    Library library;

    library.addBook(Book("Author1", "Book1", 2000));
    library.addBook(Book("Author2", "Book2", 2005));
    library.addBook(Book("Author3", "Book3", 2010));

    cout << "All books in the library:" << endl;
    library.displayAllBooks();

    Book* foundBook = library.searchBook("Author1", "Book1");
    if (foundBook) {
        cout << "Book found: " << *foundBook << endl;
    }
    else {
        cout << "Book not found." << endl;
    }

    library.issueBook(*foundBook);
    library.displayAllBooks();

    library.saveBooksToFile("library.txt");
    library.loadBooksFromFile("library.txt");

    cout << "All books in the library after loading from file:" << endl;
    library.displayAllBooks();

    return 0;
}
