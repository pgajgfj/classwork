#include <iostream>
using namespace std;
template <typename T>
class DoublyLinkedList {
private:
    
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    
    void addToFront(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    
    void addToBack(T value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

   
    void removeFromFront() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        delete temp;
    }

    
    void removeFromBack() {
        if (tail == nullptr) {
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }

        delete temp;
    }

    
    void removeAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    
    void removeByValue(T value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
    }

    
    void displayForward() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    
    void displayBackward() const {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    
    void insertAfter(Node* nodeToInsert, Node* afterNode) {
        if (nodeToInsert == nullptr || afterNode == nullptr) {
            return;
        }

        nodeToInsert->prev = afterNode;
        nodeToInsert->next = afterNode->next;
        afterNode->next = nodeToInsert;

        if (nodeToInsert->next != nullptr) {
            nodeToInsert->next->prev = nodeToInsert;
        }
        else {
            tail = nodeToInsert;
        }
    }

    
    int searchAndReplace(T oldValue, T newValue) {
        int replacements = 0;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldValue) {
                current->data = newValue;
                replacements++;
            }
            current = current->next;
        }
        return replacements;
    }

    
    DoublyLinkedList<T> operator+(const DoublyLinkedList<T>& otherList) const {
        DoublyLinkedList<T> result = *this;
        Node* current = otherList.head;
        while (current != nullptr) {
            result.addToBack(current->data);
            current = current->next;
        }
        return result;
    }

    
    void operator+=(const DoublyLinkedList<T>& otherList) {
        Node* current = otherList.head;
        while (current != nullptr) {
            addToBack(current->data);
            current = current->next;
        }
    }

    
    DoublyLinkedList<T> operator*(const DoublyLinkedList<T>& otherList) const {
        DoublyLinkedList<T> result;
        Node* current = head;
        while (current != nullptr) {
            if (otherList.contains(current->data)) {
                result.addToBack(current->data);
            }
            current = current->next;
        }
        return result;
    }

    
    void reverse() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }

        
        Node* temp = head;
        head = tail;
        tail = temp;
    }

    
    bool contains(T value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    
    ~DoublyLinkedList() {
        removeAll();
    }
};

int main() {
    DoublyLinkedList<int> list1, list2;

    list1.addToBack(1);
    list1.addToBack(2);
    list1.addToBack(3);

    list2.addToBack(3);
    list2.addToBack(4);
    list2.addToBack(5);

    cout << "List 1: ";
    list1.displayForward();

    cout << "List 2: ";
    list2.displayForward();

    DoublyLinkedList<int> resultConcat = list1 + list2;
    cout << "Concatenated List: ";
    resultConcat.displayForward();

    list1 += list2;
    cout << "List 1 after concatenation: ";
    list1.displayForward();

    DoublyLinkedList<int> resultIntersection = list1 * list2;
    cout << "Intersection List: ";
    resultIntersection.displayForward();

    cout << "Reversed List 1: ";
    list1.reverse();
    list1.displayForward();

    return 0;
}
