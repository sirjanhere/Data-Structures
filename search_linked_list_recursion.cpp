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

// Recursive search function
template <typename T>
int searchRecursive(Node<T>* head, T value, int index = 0) {
    if (head == NULL)
        return -1;  // Not found
    if (head->data == value)
        return index;
    return searchRecursive(head->next, value, index + 1);
}

int main() {
    Node<>* head = NULL;
    Node<>* tail = NULL;

    cout << "Enter elements for the linked list (press Enter on an empty line to stop):\n";
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

    cout << "Enter the value to search for: ";
    string value;
    getline(cin, value);

    int result = searchRecursive(head, value);
    if (result == -1)
        cout << "Value \"" << value << "\" not found in the list.\n";
    else
        cout << "Value \"" << value << "\" found at index: " << result << endl;

    return 0;
}
