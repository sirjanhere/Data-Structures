#include <iostream>
#include <string>
using namespace std;

template<typename T = string>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    Node(T val) : data(val), prev(NULL), next(NULL) {}
};

template<typename T = string>
class DLL {
private:
    Node<T>* head;
    Node<T>* tail;

    void forwardTraversalPrint() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseTraversalPrint() {
        Node<T>* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

public:
    DLL() : head(NULL), tail(NULL) { }

    ~DLL() {
        while (head != NULL) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
    }

    void addAtBeginning(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "List after adding at beginning: ";
        forwardTraversalPrint();
    }

    void addAtEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        // Do not print here during initial input
    }

    void addAtPosition(int pos, T val) {
        if (pos < 1) {
            cout << "Negative position invalid.\n";
            return;
        }
        if (pos == 1) {
            addAtBeginning(val);
            return;
        }
        Node<T>* temp = head;
        int count = 1;
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Position is beyond the list length, adding at end.\n";
            addAtEnd(val);
            cout << "List after adding at end: ";
            forwardTraversalPrint();
            return;
        }
        if (temp->next == NULL) {
            addAtEnd(val);
            cout << "List after adding at end: ";
            forwardTraversalPrint();
            return;
        }
        Node<T>* newNode = new Node<T>(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << "List after adding at position " << pos << ": ";
        forwardTraversalPrint();
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete at beginning.\n";
            return;
        }
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
        cout << "List after deleting at beginning: ";
        forwardTraversalPrint();
    }

    void deleteAtEnd() {
        if (tail == NULL) {
            cout << "List is empty. Nothing to delete at end.\n";
            return;
        }
        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
        cout << "List after deleting at end: ";
        forwardTraversalPrint();
    }

    void deleteAtPosition(int pos) {
        if (pos < 1) {
            cout << "Negative position invalid.\n";
            return;
        }
        if (head == NULL) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }
        Node<T>* temp = head;
        int count = 1;
        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Position is beyond the list length. Nothing to delete.\n";
            return;
        }
        if (temp == tail) {
            deleteAtEnd();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        cout << "List after deleting at position " << pos << ": ";
        forwardTraversalPrint();
    }

    bool searchElement(T val) {
        Node<T>* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Element " << val << " found at position " << pos << ".\n";
                return true;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element " << val << " not found in the list.\n";
        return false;
    }

    void reverseList() {
        Node<T>* current = head;
        Node<T>* temp = NULL;
        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != NULL) {
            head = temp->prev;
        }
        cout << "List after reversing: ";
        forwardTraversalPrint();
    }

    void traverseForward() {
        cout << "Traverse forward: ";
        forwardTraversalPrint();
    }

    void traverseReverse() {
        cout << "Traverse reverse: ";
        reverseTraversalPrint();
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    DLL<> dll;
    int n;
    cout << "Enter number of initial elements: ";
    cin >> n;
    if (n < 0) {
        cout << "Negative length not allowed. Setting to 0.\n";
        n = 0;
    }
    cout << "Enter " << n << " elements (default type string):\n";
    for (int i = 0; i < n; i++) {
        string val;
        cin >> val;
        dll.addAtEnd(val);
    }
    cout << "Initial list: ";  // Print initial list in one line!
    dll.traverseForward();

    int choice;
    do {
        cout << "\nMenu (1-based indexing):\n";
        cout << "1. Add at beginning\n2. Add at end\n3. Add at position\n";
        cout << "4. Delete at beginning\n5. Delete at end\n6. Delete at position\n";
        cout << "7. Search element\n8. Reverse list\n9. Traverse forward and print\n";
        cout << "10. Traverse reverse and print\n11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter element to add at beginning: ";
                string val; cin >> val;
                dll.addAtBeginning(val);
                break;
            }
            case 2: {
                cout << "Enter element to add at end: ";
                string val; cin >> val;
                dll.addAtEnd(val);
                cout << "List after adding at end: ";
                dll.traverseForward();
                break;
            }
            case 3: {
                cout << "Enter position (1-based) to add element: ";
                int pos; cin >> pos;
                if (pos < 1) { cout << "Invalid position.\n"; break; }
                cout << "Enter element to add: ";
                string val; cin >> val;
                dll.addAtPosition(pos, val);
                break;
            }
            case 4:
                dll.deleteAtBeginning();
                break;
            case 5:
                dll.deleteAtEnd();
                break;
            case 6: {
                cout << "Enter position (1-based) to delete element: ";
                int pos; cin >> pos;
                if (pos < 1) { cout << "Invalid position.\n"; break; }
                dll.deleteAtPosition(pos);
                break;
            }
            case 7: {
                cout << "Enter element to search: ";
                string val; cin >> val;
                dll.searchElement(val);
                break;
            }
            case 8:
                dll.reverseList();
                break;
            case 9:
                dll.traverseForward();
                break;
            case 10:
                dll.traverseReverse();
                break;
            case 11:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 11);

    return 0;
}
