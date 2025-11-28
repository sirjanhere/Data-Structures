#include <iostream>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int data;
    Node *prev, *next;
    Node(int value) {
        data = value;
        prev = next = NULL;
    }
};

// Deque class using doubly linked list
class Deque {
    Node *front, *rear;
public:
    Deque() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insertFront(int value) {
        Node *newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Inserted at front: " << value << "\n";
    }

    void insertRear(int value) {
        Node *newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << "Inserted at rear: " << value << "\n";
    }

    int deleteFront() {
        if (isEmpty()) {
            cout << "Underflow (empty)\n";
            return -1;
        }
        int value = front->data;
        Node *temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        } else {
            front->prev = NULL;
        }
        delete temp;
        cout << "Deleted from front: " << value << "\n";
        return value;
    }

    int deleteRear() {
        if (isEmpty()) {
            cout << "Underflow (empty)\n";
            return -1;
        }
        int value = rear->data;
        Node *temp = rear;
        rear = rear->prev;
        if (rear == NULL) {
            front = NULL;
        } else {
            rear->next = NULL;
        }
        delete temp;
        cout << "Deleted from rear: " << value << "\n";
        return value;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        cout << "Front element: " << front->data << "\n";
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        cout << "Rear element: " << rear->data << "\n";
        return rear->data;
    }

    int getSize() {
        int cnt = 0;
        Node *temp = front;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque elements: ";
        Node *temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    int choice, value;
    Deque dq;

    while (1) {
        cout << "\n--- Deque Menu (Linked List) ---\n";
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
