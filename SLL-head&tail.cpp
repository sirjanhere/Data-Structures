#include <iostream>
#include <string>
#include <cstddef> // for NULL
using namespace std;

template <typename T = string>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(NULL) {}
};

template <typename T = string>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SinglyLinkedList() : head(NULL), tail(NULL) {}

    // Add at beginning
    void addAtBeginning(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Add at end
    void addAtEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add at any position (1-based indexing)
    void addAtPosition(int pos, T val) {
        if (pos == 1 || !head) {
            addAtBeginning(val);
            return;
        }

        Node<T>* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of range. Adding at end.\n";
            addAtEnd(val);
            return;
        }

        Node<T>* newNode = new Node<T>(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (!newNode->next) tail = newNode;
    }

    // Delete at beginning
    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (!head) tail = NULL;
        delete temp;
    }

    // Delete at end
    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // Delete at any position (1-based indexing)
    void deleteAtPosition(int pos) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (pos < 1) {
            cout << "Invalid position! Positions start from 1.\n";
            return;
        }
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node<T>* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range.\n";
            return;
        }

        Node<T>* delNode = temp->next;
        temp->next = delNode->next;
        if (delNode == tail) tail = temp;
        delete delNode;
    }

    // Search an element
    void search(T val) {
        Node<T>* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Element found at position " << pos << " (1-based)\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found.\n";
    }

    // Reverse (modifies list)
    void reverse() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* prev = NULL;
        Node<T>* curr = head;
        Node<T>* nxt = NULL;
        tail = head;
        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
        cout << "List reversed.\n";
        traverse();
    }

    // Traverse
    void traverse() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Menu driven program
int main() {
    SinglyLinkedList<string> list;  // default type string
    int choice = -1, pos, n;
    string val;
    char initChoice;

    // Ask for initial list
    cout << "Do you want to enter an initial list? (y/n): ";
    cin >> initChoice;
    if (initChoice == 'y' || initChoice == 'Y') {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements (space-separated): ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            list.addAtEnd(val);
        }
    }

    cout << "\nInitial List:\n";
    list.traverse();

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Add at Beginning\n";
        cout << "2. Add at End\n";
        cout << "3. Add at Position (1-based)\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position (1-based)\n";
        cout << "7. Search\n";
        cout << "8. Reverse (Modify List and print)\n";
        cout << "9. Traverse (Print current list)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.addAtBeginning(val);
            list.traverse();
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.addAtEnd(val);
            list.traverse();
            break;
        case 3:
            cout << "Enter position (1-based): ";
            cin >> pos;
            if (pos < 1) {
                cout << "Invalid position! Positions start from 1.\n";
                break;  // do not ask for value
            }
            cout << "Enter value: ";
            cin >> val;
            list.addAtPosition(pos, val);
            list.traverse();
            break;
        case 4:
            list.deleteAtBeginning();
            list.traverse();
            break;
        case 5:
            list.deleteAtEnd();
            list.traverse();
            break;
        case 6:
            cout << "Enter position (1-based): ";
            cin >> pos;
            if (pos < 1) {
                cout << "Invalid position! Positions start from 1.\n";
                break;
            }
            list.deleteAtPosition(pos);
            list.traverse();
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            list.search(val);
            list.traverse();
            break;
        case 8:
            list.reverse();
            break;
        case 9:
            list.traverse();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
