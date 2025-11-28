#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

    // Recursive function to print in reverse
    void printReverseRec(Node<T>* node) {
        if (node == NULL)
            return;
        printReverseRec(node->next);
        cout << node->data << " ";
    }

public:
    LinkedList() {
        head = NULL;
    }

    void insertEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void printList() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printReverse() {
        printReverseRec(head);
        cout << endl;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    LinkedList<string> list;  // can also use int, float, char, etc.
    int n;
    string val;

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty." << endl;
        return 0;
    }

    cout << "Enter " << n << " values (one per line):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertEnd(val);
    }

    cout << "\nOriginal Linked List: ";
    list.printList();

    cout << "Linked List in Reverse (using recursion): ";
    list.printReverse();

    return 0;
}
