#include <iostream>
using namespace std;

bool contains(int* arr, int size, int elem) {
    return find(arr, arr + size, elem) != arr + size;
}

int* commonElems(int* A, int sizeA, int* B, int sizeB, int& resultSize) {
    if (sizeA <= 0 || sizeB <= 0) {
        resultSize = 0;
        return nullptr; 
    }

    int* result = new int[std::min(sizeA, sizeB)];
    resultSize = 0;

    for (int i = 0; i < sizeA; ++i) {
        if (contains(B, sizeB, A[i])) {
            result[resultSize++] = A[i];
        }
    }

    return result;
}


int* allElems(int* arr, int size) {
    int* result = new int[size];
    for (int i = 0; i < size; ++i) {
        result[i] = arr[i];
    }
    return result;
}

int* mergeResults(int* arr1, int size1, int* arr2, int size2, int* arr3, int size3, int& resultSize) {
    int* result = new int[size1 + size2 + size3];
    resultSize = 0;

    for (int i = 0; i < size1; ++i) {
        result[resultSize++] = arr1[i];
    }

    for (int i = 0; i < size2; ++i) {
        result[resultSize++] = arr2[i];
    }

    for (int i = 0; i < size3; ++i) {
        result[resultSize++] = arr3[i];
    }

    return result;
}

int main() {
    int n, m;
    cout << "Enter the size of array A: ";
    cin >> n;
    int* A = new int[n];
    cout << "Enter the elements of array A: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout << "Enter the size of array B: ";
    cin >> m;
    int* B = new int[m];
    cout << "Enter the elements of array B: ";
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    int commonSize;
    int* commonElements = commonElems(A, n, B, m, commonSize);
    int* allElementsA = allElems(A, n);
    int* allElementsB = allElems(B, m);

    int unionSize;
    int* result = mergeResults(commonElements, commonSize, allElementsA, n, allElementsB, m, unionSize);

    cout << "Result:" << endl;
    for (int i = 0; i < unionSize; ++i) {
        cout << result[i] << " ";
    }

    delete[] A;
    delete[] B;
    delete[] commonElements;
    delete[] allElementsA;
    delete[] allElementsB;
    delete[] result;

    return 0;
}
