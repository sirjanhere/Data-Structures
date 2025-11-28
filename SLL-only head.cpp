#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

// --------------------- NODE CLASS TEMPLATE ---------------------
template <typename T>
class Node {
public:
    T data;         // The data stored in this node
    Node<T>* next;  // Pointer to the next node
    Node(const T& value) : data(value), next(NULL) {}
};

// --------------------- LINKED LIST CLASS TEMPLATE ---------------------
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head; // Pointer to the first node

public:
    SinglyLinkedList() : head(NULL) {}

    bool isEmpty() const { return head == NULL; }

    // Print the list in [ a b c ] format
    void printList() const {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node<T>* temp = head;
        cout << "[ ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    void insertAtBeginning(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(const T& value, int position) {
        if (position <= 1 || isEmpty()) {
            insertAtBeginning(value);
            return;
        }
        Node<T>* newNode = new Node<T>(value);
        Node<T>* temp = head;
        for (int i = 1; i < position - 1 && temp->next != NULL; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (isEmpty()) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (isEmpty()) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node<T>* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtPosition(int position) {
        if (isEmpty()) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (position <= 1) {
            deleteAtBeginning();
            return;
        }
        Node<T>* temp = head;
        for (int i = 1; i < position - 1 && temp->next != NULL; ++i) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Position out of range." << endl;
            return;
        }
        Node<T>* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
};

// --------------------- HELPER: Read a value of type T ---------------------
template <typename T>
T readValue(const string& prompt) {
    string line;
    while (true) {
        cout << prompt;
        if (!getline(cin, line)) {
            cout << "\nInput error. Exiting.\n";
            exit(0);
        }
        stringstream ss(line);
        T value;
        if (ss >> value && ss.eof()) {
            return value; // parsed successfully
        }
        cout << "Invalid input. Please try again.\n";
    }
}

// --------------------- MAIN PROGRAM ---------------------
int main() {
    // Here we can change <int> to <double>, <string>, etc.
    SinglyLinkedList<string> list;

    // Step 1: Ask user to enter initial list
    cout << "Enter the initial list in format [a b c] (or press Enter for empty): ";
    string inputLine;
    getline(cin, inputLine);

    if (!inputLine.empty() && inputLine[0] == '[' && inputLine[inputLine.size() - 1] == ']') {
        string inside = inputLine.substr(1, inputLine.size() - 2);
        stringstream ss(inside);
        string val;
        while (ss >> val) {
            list.insertAtEnd(val);
        }
    }

    cout << "Initial list: ";
    list.printList();

    // Step 2: Menu
    while (true) {
        cout << "\n----- Singly Linked List Menu -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Print List\n";
        cout << "8. Exit\n";

        int choice = readValue<int>("Enter your choice: ");

        if (choice == 1) {
            string value = readValue<string>("Enter value to insert at beginning: ");
            list.insertAtBeginning(value);
            cout << "Updated list: ";
            list.printList();
        } else if (choice == 2) {
            string value = readValue<string>("Enter value to insert at end: ");
            list.insertAtEnd(value);
            cout << "Updated list: ";
            list.printList();
        } else if (choice == 3) {
            string value = readValue<string>("Enter value to insert: ");
            int position = readValue<int>("Enter position to insert at (1-based index): ");
            list.insertAtPosition(value, position);
            cout << "Updated list: ";
            list.printList();
        } else if (choice == 4) {
            list.deleteAtBeginning();
            cout << "Updated list: ";
            list.printList();
        } else if (choice == 5) {
            list.deleteAtEnd();
            cout << "Updated list: ";
            list.printList();
        } else if (choice == 6) {
            int position = readValue<int>("Enter position to delete (1-based index): ");
            list.deleteAtPosition(position);
            cout << "Updated list: ";
            list.printList();
        } else if (choice == 7) {
            list.printList();
        } else if (choice == 8) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice. Enter a number 1..8.\n";
        }
    }

    return 0;
}
