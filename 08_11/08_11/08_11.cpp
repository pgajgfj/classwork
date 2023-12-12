#include <iostream>
using namespace std;
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}

};

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

    void clearHelper(TreeNode<T>* node) {
        if (node) {
            clearHelper(node->left);
            clearHelper(node->right);
            delete node;
        }
    }

    void insertHelper(TreeNode<T>*& node, T value) {
        if (!node) {
            node = new TreeNode<T>(value);
        }
        else if (value < node->data) {
            insertHelper(node->left, value);
        }
        else {
            insertHelper(node->right, value);
        }
    }

    TreeNode<T>* findMax(TreeNode<T>* node) {
        while (node->right) {
            node = node->right;
        }
        return node;
    }

    TreeNode<T>* findMin(TreeNode<T>* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    void deleteNode(TreeNode<T>*& node, T value) {
        if (!node) {
            return;
        }

        if (value < node->data) {
            deleteNode(node->left, value);
        }
        else if (value > node->data) {
            deleteNode(node->right, value);
        }
        else {
            if (!node->left && !node->right) {
                delete node;
                node = nullptr;
            }
            else if (!node->left) {
                TreeNode<T>* temp = node;
                node = node->right;
                delete temp;
            }
            else if (!node->right) {
                TreeNode<T>* temp = node;
                node = node->left;
                delete temp;
            }
            else {
                TreeNode<T>* successor = findMin(node->right);
                node->data = successor->data;
                deleteNode(node->right, successor->data);
            }
        }
    }

    void printRangeHelper(TreeNode<T>* node, const T& left, const T& right) {
        if (!node) {
            return;
        }

        if (node->data > left) {
            printRangeHelper(node->left, left, right);
        }

        if (node->data >= left && node->data <= right) {
            std::cout << node->data << " ";
        }

        if (node->data < right) {
            printRangeHelper(node->right, left, right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        clear();
    }

    void insert(T value) {
        insertHelper(root, value);
    }

    void clear() {
        clearHelper(root);
        root = nullptr;
    }

    void removeMax() {
        if (root) {
            TreeNode<T>* maxNode = findMax(root);
            deleteNode(root, maxNode->data);
        }
    }

    void removeMin() {
        if (root) {
            TreeNode<T>* minNode = findMin(root);
            deleteNode(root, minNode->data);
        }
    }

    void printRange(const T& left, const T& right) {
        printRangeHelper(root, left, right);
        cout << endl;
    }

    void deleteSubtree(TreeNode<T>*& node) {
        clearHelper(node);
        node = nullptr;
    }
    TreeNode<T>* getRoot() const {
        return root;
    }
};

int main() {
    BinaryTree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Original Tree: ";
    tree.printRange(INT_MIN, INT_MAX);

    tree.removeMax();
    cout << "Tree after removing the maximum element: ";
    tree.printRange(INT_MIN, INT_MAX);

    tree.removeMin();
    cout << "Tree after removing the minimum element: ";
    tree.printRange(INT_MIN, INT_MAX);

    int leftRange = 35;
    int rightRange = 75;
    cout << "Elements in the range [" << leftRange << ", " << rightRange << "]: ";
    tree.printRange(leftRange, rightRange);

    TreeNode<int>* subtreeRoot = tree.getRoot()->left;
    tree.deleteSubtree(subtreeRoot);
    cout << "Tree after deleting the subtree rooted at " << subtreeRoot->data << ": ";
    tree.printRange(INT_MIN, INT_MAX);



    return 0;
}
