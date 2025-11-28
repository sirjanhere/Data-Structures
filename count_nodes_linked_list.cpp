#include <iostream>
#include <string>
using namespace std;

template <typename T = string>
class Node {
public:
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

template <typename T = string>
class LinkedList {
private:
    Node<T>* head;

    // Recursive function to count nodes
    int countRec(Node<T>* node) {
        if (node == NULL)
            return 0;
        return 1 + countRec(node->next);
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
        if (head == NULL) {
            cout << "(empty list)" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int countNodes() {
        return countRec(head);
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    LinkedList<string> list;
    string value;

    cout << "Enter elements for the linked list (type END to stop):" << endl;

    while (true) {
        getline(cin, value);
        if (value == "END" || value == "end")
            break;
        if (value.empty())
            continue;
        list.insertEnd(value);
    }

    cout << "\nLinked List contents: ";
    list.printList();

    int count = list.countNodes();
    cout << "Number of nodes in the linked list: " << count << endl;

    return 0;
}
