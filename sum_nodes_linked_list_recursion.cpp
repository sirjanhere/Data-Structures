#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T = double>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(NULL) {}
};

// Recursive function to find sum of all nodes
template <typename T>
T sumRecursive(Node<T>* head) {
    if (head == NULL)
        return 0; // base case: empty list
    return head->data + sumRecursive(head->next);
}

int main() {
    Node<>* head = NULL;
    Node<>* tail = NULL;

    cout << "Enter numeric elements (integers or floats) one per line.\n";
    cout << "Press Enter on an empty line to stop:\n";

    string input;
    while (true) {
        getline(cin, input);
        if (input.empty())
            break;
        stringstream ss(input);
        double value;
        if (!(ss >> value)) {
            cout << "Invalid number, skipping...\n";
            continue;
        }
        Node<>* newNode = new Node<>(value);
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

    double totalSum = sumRecursive(head);
    cout << "Sum of all nodes: " << totalSum << endl;

    return 0;
}
