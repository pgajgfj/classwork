#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T, size_t Rows, size_t Cols>
class Matrix {
private:
    vector<vector<T>> data;

public:
    
    Matrix(const T& value) : data(Rows, vector<T>(Cols, value)) {}

    
    void display() const {
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    
    T maxElement() const {
        T maxElem = data[0][0];
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                if (data[i][j] > maxElem) {
                    maxElem = data[i][j];
                }
            }
        }
        return maxElem;
    }

    
    T minElement() const {
        T minElem = data[0][0];
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                if (data[i][j] < minElem) {
                    minElem = data[i][j];
                }
            }
        }
        return minElem;
    }

    
    bool searchValue(const T& value) const {
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                if (data[i][j] == value) {
                    return true;
                }
            }
        }
        return false;
    }

    
    T& operator()(int r, int c) {
        return data[r][c];
    }

    T operator()(int r, int c) const {
        return data[r][c];
    }

   
    T sumElements() const {
        T sum = 0;
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                sum += data[i][j];
            }
        }
        return sum;
    }

    
    Matrix operator+(const Matrix& other) const {
        Matrix result(0);
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                result(i, j) = data[i][j] + other(i, j);
            }
        }
        return result;
    }

    
    Matrix operator+(const T& value) const {
        Matrix result(0);
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                result(i, j) = data[i][j] + value;
            }
        }
        return result;
    }

    
    friend Matrix operator+(const T& value, const Matrix& matrix) {
        return matrix + value;
    }

    
    Matrix& operator+=(const T& value) {
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                data[i][j] += value;
            }
        }
        return *this;
    }

    
    bool operator==(const Matrix& other) const {
        return data == other.data;
    }

    
    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }
};

int main() {
    
    Matrix<int, 2, 3> intMatrix(1);
    intMatrix.display();
    cout << "Max Element: " << intMatrix.maxElement() << endl;
    cout << "Min Element: " << intMatrix.minElement() << endl;
    cout << "Search Value 2: " << intMatrix.searchValue(2) << endl;
    cout << "Sum of Elements: " << intMatrix.sumElements() << endl;
    intMatrix += 5;
    cout << "Matrix After Adding 5: " << endl;
    intMatrix.display();

    
    Matrix<double, 2, 3> doubleMatrix(2.5);
    doubleMatrix.display();
    cout << "Max Element: " << doubleMatrix.maxElement() << endl;
    cout << "Min Element: " << doubleMatrix.minElement() << endl;
    cout << "Search Value 3.5: " << doubleMatrix.searchValue(3.5) << endl;
    cout << "Sum of Elements: " << doubleMatrix.sumElements() << endl;
    doubleMatrix += 1.5;
    cout << "Matrix After Adding 1.5: " << endl;
    doubleMatrix.display();

    
    Matrix<string, 2, 3> stringMatrix("abc");
    stringMatrix.display();
    cout << "Max Element: " << stringMatrix.maxElement() << endl;
    cout << "Min Element: " << stringMatrix.minElement() << endl;
    cout << "Search Value 'xyz': " << stringMatrix.searchValue("xyz") << endl;
    cout << "Sum of Elements: " << stringMatrix.sumElements() << endl;
    stringMatrix += "def";
    cout << "Matrix After Adding 'def': " << endl;
    stringMatrix.display();

   
    Matrix<int, 2, 3> intMatrix2(2);
    Matrix<int, 2, 3> sumMatrix = intMatrix + intMatrix2;
    cout << "Matrix Sum: " << endl;
    sumMatrix.display();

    
    Matrix<int, 2, 3> addedValueMatrix = intMatrix + 3;
    cout << "Matrix After Adding 3: " << endl;
    addedValueMatrix.display();

    
    Matrix<int, 2, 3> addedMatrixValue = 4 + intMatrix;
    cout << "Matrix After Adding 4: " << endl;
    addedMatrixValue.display();

    
    intMatrix += 10;
    cout << "Matrix After Adding 10 (Compound Assignment): " << endl;
    intMatrix.display();

    
    cout << "Matrix Equality Check: " << (intMatrix == intMatrix2) << endl;

    return 0;
}
