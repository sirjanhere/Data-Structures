#include <iostream>
#include <string>
using namespace std;

template <typename T = string>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(NULL) {}
};

// Recursive function to find the length of the linked list
template <typename T>
int lengthRecursive(Node<T>* head) {
    if (!head)
        return 0;  // base case: empty list
    return 1 + lengthRecursive(head->next);
}

int main() {
    Node<>* head = NULL;
    Node<>* tail = NULL;

    cout << "Enter elements for the linked list (one per line, press Enter on empty line to stop):\n";
    string input;
    while (true) {
        getline(cin, input);
        if (input.empty())
            break;
        Node<>* newNode = new Node<>(input);
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (!head) {
        cout << "The list is empty.\n";
        return 0;
    }

    int length = lengthRecursive(head);
    cout << "Length of the linked list: " << length << endl;

    return 0;
}
