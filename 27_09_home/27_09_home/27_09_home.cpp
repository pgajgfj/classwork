#include <iostream>

using namespace std;

// Завдання 1: Додати стовпчик в зазначену позицію
void addColumn(int** matrix, int numRows, int numCols, int columnPosition, const int* values) {
    if (columnPosition < 0 || columnPosition > numCols) {
        cout << "Invalid column position." << endl;
        return;
    }

    int* newColumnValues = new int[numRows];

    for (int i = 0; i < numRows; ++i) {
        newColumnValues[i] = values[i];
    }

    for (int i = 0; i < numRows; ++i) {
        int* newRow = new int[numCols + 1];
        for (int j = 0; j < columnPosition; ++j) {
            newRow[j] = matrix[i][j];
        }
        newRow[columnPosition] = newColumnValues[i];
        for (int j = columnPosition + 1; j <= numCols; ++j) {
            newRow[j] = matrix[i][j - 1];
        }

        delete[] matrix[i];
        matrix[i] = newRow;
    }
    delete[] newColumnValues;
}

// Завдання 2: Видалити стовпчик за вказаним номером
void removeColumn(int** matrix, int numRows, int numCols, int columnNumber) {
    if (columnNumber < 0 || columnNumber >= numCols) {
        cout << "Invalid column number." << endl;
        return;
    }

    for (int i = 0; i < numRows; ++i) {
        int* newRow = new int[numCols - 1];
        for (int j = 0, k = 0; j < numCols; ++j) {
            if (j != columnNumber) {
                newRow[k++] = matrix[i][j];
            }
        }

        delete[] matrix[i];
        matrix[i] = newRow;
    }
}

// Завдання 3: Циклічний зсув рядків та/або стовпчиків
void cyclicShift(int** matrix, int numRows, int numCols, int shiftCount, char direction) {
    shiftCount %= numCols;

    if (direction == 'r') {
        for (int i = 0; i < numRows; ++i) {
            for (int k = 0; k < shiftCount; ++k) {
                int lastElement = matrix[i][numCols - 1];
                for (int j = numCols - 1; j > 0; --j) {
                    matrix[i][j] = matrix[i][j - 1];
                }
                matrix[i][0] = lastElement;
            }
        }
    }
    else if (direction == 'l') {
        for (int i = 0; i < numRows; ++i) {
            for (int k = 0; k < shiftCount; ++k) {
                int firstElement = matrix[i][0];
                for (int j = 0; j < numCols - 1; ++j) {
                    matrix[i][j] = matrix[i][j + 1];
                }
                matrix[i][numCols - 1] = firstElement;
            }
        }
    }
    else {
        cout << "Invalid direction. Use 'r' or 'l'." << endl;
    }
}


void printMatrix(int** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}


void deleteMatrix(int** matrix, int numRows) {
    for (int i = 0; i < numRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
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
            matrix[i][j] = 0;
        }
    }

   
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix, M, N);

    // Завдання 1: Додати стовпчик
    int* newColumnValues = new int[M];
    cout << "Enter the values for the new column:" << endl;
    for (int i = 0; i < M; ++i) {
        cin >> newColumnValues[i];
    }

    int newColumnPosition;
    cout << "Enter the position to add the new column: ";
    cin >> newColumnPosition;

    addColumn(matrix, M, N, newColumnPosition, newColumnValues);

    
    cout << "Matrix after adding a column:" << endl;
    printMatrix(matrix, M, N + 1);

    // Завдання 2: Видалити стовпчик
    int columnToDelete;
    cout << "Enter the column number to delete: ";
    cin >> columnToDelete;

    removeColumn(matrix, M, N + 1, columnToDelete);

    
    cout << "Matrix after removing a column:" << endl;
    printMatrix(matrix, M, N);

    // Завдання 3: Циклічний зсув
    int shiftCount;
    char shiftDirection;
    cout << "Enter the number of positions to shift: ";
    cin >> shiftCount;
    cout << "Enter the shift direction ('r' for right, 'l' for left): ";
    cin >> shiftDirection;

    cyclicShift(matrix, M, N, shiftCount, shiftDirection);

    
    cout << "Matrix after cyclic shift:" << endl;
    printMatrix(matrix, M, N);

    
    delete[] newColumnValues;
    deleteMatrix(matrix, M);

    return 0;
}
