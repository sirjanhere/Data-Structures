#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front, rear, size;

public:
    // Constructor
    CircularQueue(int capacity) {
        arr = new int[capacity];
        size = capacity;
        front = rear = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % size) == front;
    }

    // Insert element at rear
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }

    // Remove element from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int data = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return data;
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
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
};

// Example usage
int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();              // 10 20 30
    cout << q.dequeue() << endl;  // 10
    cout << q.getFront() << endl; // 20
    cout << q.getRear() << endl;  // 30
    q.display();              // 20 30
    return 0;
}
