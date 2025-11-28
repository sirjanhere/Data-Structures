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

// Recursive function to reverse the linked list
template <typename T>
Node<T>* reverseRecursive(Node<T>* head) {
    if (!head || !head->next)  // base case: empty list or single node
        return head;

    Node<T>* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// Function to print the list
template <typename T>
void printList(Node<T>* head) {
    Node<T>* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node<>* head = NULL;
    Node<>* tail = NULL;

    cout << "Enter elements for the linked list (press Enter on empty line to stop):\n";
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

    cout << "Original list:\n";
    printList(head);

    head = reverseRecursive(head);

    cout << "Reversed list:\n";
    printList(head);

    return 0;
}
