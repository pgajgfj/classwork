#include <iostream>

using namespace std;

// Завдання 1: Транспонування матриці
void transposeMatrix(int** matrix, int numRows, int numCols) {
    int** transposedMatrix = new int* [numCols];
    for (int i = 0; i < numCols; ++i) {
        transposedMatrix[i] = new int[numRows];
    }

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    
    for (int i = 0; i < numRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    
    matrix = transposedMatrix;
}

// Завдання 2*: Динамічний масив для імен та телефонів
void manageContactList() {
    const int MAX_CONTACTS = 100;

    string* names = new string[MAX_CONTACTS];
    string* phones = new string[MAX_CONTACTS];

    int numContacts = 0;

    while (true) {
        cout << "1. Add Contact" << endl;
        cout << "2. Search by Name" << endl;
        cout << "3. Search by Phone Number" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            if (numContacts < MAX_CONTACTS) {
                cout << "Enter name: ";
                cin >> names[numContacts];

                cout << "Enter phone number: ";
                cin >> phones[numContacts];

                ++numContacts;
            }
            else {
                cout << "Contact list is full." << endl;
            }
            break;

        case 2:
            cout << "Enter name to search: ";
            string searchName;
            cin >> searchName;

            for (int i = 0; i < numContacts; ++i) {
                if (names[i] == searchName) {
                    cout << "Name: " << names[i] << ", Phone: " << phones[i] << endl;
                    break;
                }
            }
            cout << "Contact not found." << endl;
            break;

        case 3:
            cout << "Enter phone number to search: ";
            string searchPhone;
            cin >> searchPhone;

            for (int i = 0; i < numContacts; ++i) {
                if (phones[i] == searchPhone) {
                    cout << "Name: " << names[i] << ", Phone: " << phones[i] << endl;
                    break;
                }
            }
            cout << "Contact not found." << endl;
            break;

        case 4:
            
            delete[] names;
            delete[] phones;
            return;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

int main() {
    
    int M, N;
    cout << "Enter the number of rows (M): ";
    cin >> M;
    cout << "Enter the number of columns (N): ";
    cin >> N;

    int** matrix = new int* [M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    transposeMatrix(matrix, M, N);

    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    
    manageContactList();

    return 0;
}
