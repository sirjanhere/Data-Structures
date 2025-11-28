#include <iostream>
using namespace std;

// Node for circular linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularQueue {
private:
    Node *front, *rear;

public:
    // Constructor
    CircularQueue() {
        front = rear = NULL;
    }

    // Destructor
    ~CircularQueue() {
        while (!isEmpty())
            dequeue();
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Check if queue is full (never full: uses dynamic memory)
    bool isFull() {
        return false;
    }

    // Insert an element at rear
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    // Remove an element from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int result = front->data;
        Node *temp = front;
        if (front == rear) { // only one node
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
        }
        delete temp;
        return result;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->data;
    }

    // Display all elements in circular queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

// Example usage
int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();               // 10 20 30
    cout << q.dequeue() << endl;   // 10
    cout << q.getFront() << endl;  // 20
    cout << q.getRear() << endl;   // 30
    q.display();               // 20 30
    return 0;
}
