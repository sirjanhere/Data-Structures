#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T x;
    Node* prev;
    Node* next;

    Node(T val) {
        x = val;
        prev = NULL;
        next = NULL;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Add at beginning
    void addatbeg(T x, bool print = true) {
        Node<T>* newNode = new Node<T>(x);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        if (print) printList();
    }

    // Add at end
    void addatend(T x, bool print = true) {
        Node<T>* newNode = new Node<T>(x);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) current = current->next;
            current->next = newNode;
            newNode->prev = current;
        }
        if (print) printList();
    }

    // Delete at beginning
    void delatbeg() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
        printList();
    }

    // Delete at end
    void delatend() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = NULL;
        } else {
            Node<T>* current = head;
            while (current->next) current = current->next;
            current->prev->next = NULL;
            delete current;
        }
        printList();
    }

    // Add at any position (1-based)
    void addatanypos(int pos, T x) {
        if (pos <= 1) {
            addatbeg(x);
            return;
        }
        Node<T>* newNode = new Node<T>(x);
        Node<T>* current = head;
        for (int i = 1; i < pos - 1 && current; i++) current = current->next;

        if (!current || !current->next) {
            addatend(x);
            delete newNode;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        printList();
    }

    // Delete at any position (1-based)
    void delatanypos(int pos) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (pos <= 1) {
            delatbeg();
            return;
        }

        Node<T>* current = head;
        for (int i = 1; i < pos && current; i++) current = current->next;

        if (!current) {
            cout << "Invalid position.\n";
            return;
        }

        if (!current->next) {
            delatend();
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        printList();
    }

    // Search
    void search(T x) {
        Node<T>* current = head;
        int pos = 1;
        while (current) {
            if (current->x == x) {
                cout << "Element " << x << " found at position " << pos << ".\n";
                return;
            }
            current = current->next;
            pos++;
        }
        cout << "Element " << x << " not found in the list.\n";
    }

    // Print list
    void printList() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cout << "List: ";
        Node<T>* current = head;
        while (current) {
            cout << current->x << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Print reverse
    void printReverse() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* current = head;
        while (current->next) current = current->next;
        cout << "Reverse List: ";
        while (current) {
            cout << current->x << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList<string> dll; // string type allows any data
    int choice, pos, n;
    string x;

    // Initial list creation
    cout << "Enter number of elements to create initial list: ";
    cin >> n;
    cout << "Enter " << n << " elements (numbers, letters, or strings): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        dll.addatend(x, false); // do not print while adding
    }

    cout << "Initial List: ";
    dll.printList(); // print complete initial list once

    // Menu-driven operations
    do {
        cout << "\nMenu:\n";
        cout << "1. Add at Beginning\n";
        cout << "2. Add at End\n";
        cout << "3. Delete at Beginning\n";
        cout << "4. Delete at End\n";
        cout << "5. Add at Position (1-based index)\n";
        cout << "6. Delete at Position (1-based index)\n";
        cout << "7. Search\n";
        cout << "8. Print List\n";
        cout << "9. Print Reverse\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element x: ";
                cin >> x;
                dll.addatbeg(x);
                break;
            case 2:
                cout << "Enter element x: ";
                cin >> x;
                dll.addatend(x);
                break;
            case 3:
                dll.delatbeg();
                break;
            case 4:
                dll.delatend();
                break;
            case 5:
                cout << "Enter position (1-based index): ";
                cin >> pos;
                cout << "Enter element x: ";
                cin >> x;
                dll.addatanypos(pos, x);
                break;
            case 6:
                cout << "Enter position (1-based index): ";
                cin >> pos;
                dll.delatanypos(pos);
                break;
            case 7:
                cout << "Enter element x to search: ";
                cin >> x;
                dll.search(x);
                break;
            case 8:
                dll.printList();
                break;
            case 9:
                dll.printReverse();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
