#include <iostream>
#include <string>
using namespace std;

template <typename T>//one-dimensional array
void inputArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter element [" << i << "]: ";
        cin >> arr[i];
    }
}

template <typename T>//one-dimensional array
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>//one-dimensional array
int indexOfElement(T arr[], int size, T element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>//one-dimensional array
int lastIndexOfElement(T arr[], int size, T element) {
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>//one-dimensional array
void shuffleArray(T arr[], int size, int shuffleCount) {
    for (int i = 0; i < shuffleCount; i++) {
        int index1 = rand() % size;
        int index2 = rand() % size;
        swap(arr[index1], arr[index2]);
    }
}

template <typename T>
void sortArrayAscending(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void sortArrayDescending(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int indexOfElement(char arr[], int size, char element) {
    for (int i = 0; i < size; i++) {
        if (tolower(arr[i]) == tolower(element)) {
            return i;
        }
    }
    return -1;
}

template <typename T>//two-dimensional array
void inputMatrix(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

template <typename T>
void displayMatrix(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
T maxInMatrix(T** matrix, int rows, int cols) {
    T max = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

template <typename T>
bool isRowSorted(T** matrix, int row, int cols) {
    for (int j = 0; j < cols - 1; j++) {
        if (matrix[row][j] > matrix[row][j + 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool areAllRowsSorted(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (!isRowSorted(matrix, i, cols)) {
            return false;
        }
    }
    return true;
}

int main()
{
    // Integer array
    int intArray[5];
    inputArray(intArray, 5);
    displayArray(intArray, 5);
    int index = indexOfElement(intArray, 5, 3);
    cout << "Index of the first occurrence of 3: " << index << endl;

    // Fractional array
    double doubleArray[4];
    inputArray(doubleArray, 4);
    displayArray(doubleArray, 4);
    int lastIndex = lastIndexOfElement(doubleArray, 4, 2.5);
    cout << "Index of the last occurrence of 2.5: " << lastIndex << endl;

    // Character array
    char charArray[6];
    inputArray(charArray, 6);
    displayArray(charArray, 6);
    int shuffleCount = 3;
    shuffleArray(charArray, 6, shuffleCount);
    cout << "Array after shuffling: ";
    displayArray(charArray, 6);
    index = indexOfElement(charArray, 6, 'a');
    cout << "The index of the first occurrence of 'a': " << index << endl;

    // String array (string)
    string stringArray[3];
    inputArray(stringArray, 3);
    displayArray(stringArray, 3);
    sortArrayAscending(stringArray, 3);
    cout << "Array after ascending sorting: ";
    displayArray(stringArray, 3);

    // Integer two-dimensional array
    int** intMatrix;
    int rows = 3;
    int cols = 4;
    intMatrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        intMatrix[i] = new int[cols];
    }
    inputMatrix(intMatrix, rows, cols);
    displayMatrix(intMatrix, rows, cols);
    int maxElement = maxInMatrix(intMatrix, rows, cols);
    cout << "The largest element: " << maxElement << endl;

    // String two-dimensional array
    string** stringMatrix;
    rows = 2;
    cols = 3;
    stringMatrix = new string * [rows];
    for (int i = 0; i < rows; i++) {
        stringMatrix[i] = new string[cols];
    }
    inputMatrix(stringMatrix, rows, cols);
    displayMatrix(stringMatrix, rows, cols);
    bool sorted = areAllRowsSorted(stringMatrix, rows, cols);
    if (sorted) {
        cout << "All rows are sorted in ascending order." << endl;
    }
    else {
        cout << "Not all rows are in ascending order." << endl;
    }

    // Release allocated memory for two-dimensional arrays
    for (int i = 0; i < rows; i++) {
        delete[] intMatrix[i];
        delete[] stringMatrix[i];
    }
    delete[] intMatrix;
    delete[] stringMatrix;

    return 0;
}
