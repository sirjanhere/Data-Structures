#include <iostream>
#define MAX 100

using namespace std;

class Deque {
    int arr[MAX];
    int front, rear, size;
public:
    Deque(int size) {
        front = -1;
        rear = 0;
        this->size = size;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1) { // If deque is empty
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front = front - 1;
        }
        arr[front] = key;
        cout << "Inserted at front: " << key << "\n";
    }

    void insertRear(int key) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1) { // If deque is empty
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        arr[rear] = key;
        cout << "Inserted at rear: " << key << "\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        cout << "Deleted from front: " << arr[front] << "\n";
        if (front == rear) { // only one element
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << "\n";
        if (front == rear) { // only one element
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear = rear - 1;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        cout << "Front element: " << arr[front] << "\n";
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        cout << "Rear element: " << arr[rear] << "\n";
        return arr[rear];
    }

    int getSize() {
        if (isEmpty()) return 0;
        if (rear >= front) return rear - front + 1;
        else return size - (front - rear - 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};

int main() {
    int n, choice, value;
    cout << "Enter deque size: ";
    cin >> n;
    Deque dq(n);

    while (1) {
        cout << "\n--- Deque Menu ---\n";
        cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Get Front\n6. Get Rear\n7. Display\n8. Get Size\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> value;
            dq.insertFront(value);
            break;
        case 2:
            cout << "Enter value to insert at rear: ";
            cin >> value;
            dq.insertRear(value);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.getFront();
            break;
        case 6:
            dq.getRear();
            break;
        case 7:
            dq.display();
            break;
        case 8:
            cout << "Size: " << dq.getSize() << "\n";
            break;
        case 9:
            cout << "Exiting!\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
