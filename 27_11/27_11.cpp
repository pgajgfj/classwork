#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    // Завдання І

    // 1.
    vector<int> v1, v2(10, 0), v3, v4, v5;

    cout << "Enter elements for v1 (Ctrl+Z to stop): ";
    int input;
    while (cin >> input) {
        v1.push_back(input);
    }

    cout << "Enter number of elements for v3: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        v3.push_back(rand() % 100);  
    }

    v4 = v1;
    v5.assign(v3.begin() + 1, v3.end() - 1);

    // 2.
    cout << "Elements of v3: ";
    for (const auto& elem : v3) {
        cout << elem << " ";
    }

    ofstream outFile("Numbers.txt");
    cout << "\nElements of v1 in reverse order (written to Numbers.txt):\n";
    for (auto it = v1.rbegin(); it != v1.rend(); ++it) {
        cout << *it << " ";
        outFile << *it << " ";
    }

    // 3.
    v2.clear();
    for (int i = 1; i <= 10; ++i) {
        v2.push_back(i);
    }

    random_shuffle(v2.begin(), v2.end());
    v2.erase(v2.begin() + 1);
    v2.pop_back();

    cout << "\nElements of v2 after shuffling and removing 2nd and last elements: ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }

    // 4.
    for (auto& elem : v4) {
        v4.insert(v4.begin(), elem);
        ++elem;
    }

    // 5.
    v5.clear();
    for (const auto& elem : v4) {
        if (elem % 2 == 0) {
            v5.push_back(elem / 2);
        }
    }

    cout << "\nElements of v5 after copying even elements from v4 and halving them: ";
    for (const auto& elem : v5) {
        cout << elem << " ";
    }

    // 6.
    int searchValue;
    cout << "\nEnter a value to search in v5: ";
    cin >> searchValue;

    auto it = find(v5.begin(), v5.end(), searchValue);
    while (it != v5.end()) {
        cout << "Found at position: " << distance(v5.begin(), it) << "\n";
        it = find(++it, v5.end(), searchValue);
    }

    int countResult = std::count(v5.begin(), v5.end(), searchValue);
    cout << "Total occurrences: " << countResult << "\n";

    // 7.
    swap(v4, v5);

    // Завдання II

    
    vector<vector<int>> multiplicationTable(10, vector<int>(10, 0));

    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            multiplicationTable[i - 1][j - 1] = i * j;
        }
    }

    
    cout << "\nMultiplication Table:\n";
    for (const auto& row : multiplicationTable) {
        for (const auto& elem : row) {
            cout << elem << "\t";
        }
        cout << "\n";
    }

    return 0;
}
