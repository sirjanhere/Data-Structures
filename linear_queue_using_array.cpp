#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, capacity;

public:
    // Constructor
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return rear == capacity - 1;
    }

    // Insert an element at rear
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
    	rear++;
        arr[rear] = value;
    }

    // Remove an element from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
        } else {
            front++;
        }
        return value;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }

    // Display all elements in queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Example usage
int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();          // 10 20 30
    cout << q.dequeue() << endl;     // 10
    cout << q.getFront() << endl;    // 20
    cout << q.getRear() << endl;     // 30
    q.display();          // 20 30
    return 0;
}
