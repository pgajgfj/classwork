#include <iostream>

using namespace std;


template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};


template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    
    void addElement(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    
    LinkedList<T> clone() {
        LinkedList<T> clonedList;
        Node<T>* current = head;
        while (current != nullptr) {
            clonedList.addElement(current->data);
            current = current->next;
        }
        return clonedList;
    }

    
    LinkedList<T> operator+(const LinkedList<T>& otherList) {
        LinkedList<T> result;
        Node<T>* current = head;
        while (current != nullptr) {
            result.addElement(current->data);
            current = current->next;
        }

        current = otherList.head;
        while (current != nullptr) {
            result.addElement(current->data);
            current = current->next;
        }

        return result;
    }

   
    LinkedList<T> operator*(const LinkedList<T>& otherList) {
        LinkedList<T> result;
        Node<T>* current = head;
        while (current != nullptr) {
            if (otherList.contains(current->data)) {
                result.addElement(current->data);
            }
            current = current->next;
        }

        return result;
    }

private:
    
    bool contains(T value) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    LinkedList<int> list1, list2;

   
    list1.addElement(1);
    list1.addElement(2);
    list1.addElement(3);

    
    list2.addElement(3);
    list2.addElement(4);
    list2.addElement(5);

    
    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    
    LinkedList<int> clonedList = list1.clone();
    cout << "Cloned List: ";
    clonedList.display();

    
    LinkedList<int> combinedList = list1 + list2;
    cout << "Combined List: ";
    combinedList.display();

    
    LinkedList<int> commonElementsList = list1 * list2;
    cout << "Common Elements List: ";
    commonElementsList.display();

    return 0;
}
