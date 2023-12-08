#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class PriorityQueue {
private:
    struct QueueNode {
        int value;
        int priority;

        QueueNode(int val, int pri) : value(val), priority(pri) {}
    };

    struct ComparePriority {
        bool operator()(const QueueNode& lhs, const QueueNode& rhs) const {
            return lhs.priority < rhs.priority;
        }
    };

    priority_queue<QueueNode, vector<QueueNode>, ComparePriority> pq;

public:

    bool IsEmpty() const {
        return pq.empty();
    }

   
    bool IsFull() const {
        return false;
    }


    void InsertWithPriority(int value, int priority) {
        pq.push(QueueNode(value, priority));
    }

    
    void PullHighestPriorityElement() {
        if (!pq.empty()) {
            pq.pop();
        }
    }


    int Peek() const {
        if (!pq.empty()) {
            return pq.top().value;
        }
        return -1; 
    }

    
    void Show() const {
        priority_queue<QueueNode, vector<QueueNode>, ComparePriority> tempPQ = pq;

        while (!tempPQ.empty()) {
            cout << "Value: " << tempPQ.top().value << ", Priority: " << tempPQ.top().priority << endl;
            tempPQ.pop();
        }
    }
};

int main() {
    PriorityQueue priorityQueue;

    
    priorityQueue.InsertWithPriority(10, 3);
    priorityQueue.InsertWithPriority(20, 1);
    priorityQueue.InsertWithPriority(30, 2);

   
    cout << "Queue after insertion:" << endl;
    priorityQueue.Show();

    
    cout << "Peek at the highest priority element: " << priorityQueue.Peek() << endl;

  
    priorityQueue.PullHighestPriorityElement();

   
    cout << "Queue after pulling the highest priority element:" << endl;
    priorityQueue.Show();

    return 0;
}
