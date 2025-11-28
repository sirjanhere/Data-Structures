#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Linear Queue with Linked List
class Queue {
private:
    Node *front, *rear;

public:
    // Constructor
    Queue() {
        front = rear = NULL;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty())
            dequeue();
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Queue is never "full" (dynamic memory)
    bool isFull() {
        return false;
    }

    // Insert element at rear
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove element from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int result = front->data;
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
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

    // Display all elements in queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Example usage
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();           // 10 20 30
    cout << q.dequeue() << endl;        // 10
    cout << q.getFront() << endl;       // 20
    cout << q.getRear() << endl;        // 30
    q.display();           // 20 30
    return 0;
}
