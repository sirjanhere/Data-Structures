// Recursive function to print all elements of a linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) { data = val; next = NULL; prev = NULL; }
};

void printList(Node *head, Node *curr, int type, bool first) {
    // For non-circular lists: stop at NULL
    if ((type == 1 || type == 2) && curr == NULL)
        return;
    // For circular lists: stop when we return to head after first node
    if ((type == 3 || type == 4) && !first && curr == head)
        return;

    cout << curr->data << " ";
    printList(head, curr->next, type, false);
}

int main() {
    int n, type;
    cout << "Choose linked list type:\n";
    cout << "1. Singly Linked List\n";
    cout << "2. Doubly Linked List\n";
    cout << "3. Circular Singly Linked List\n";
    cout << "4. Circular Doubly Linked List\n";
    cout << "Enter choice (1/2/3/4): ";
    cin >> type;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter the node values:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            if (type == 2 || type == 4)
                newNode->prev = tail;
            tail = newNode;
        }
    }

    // Link for circular singly
    if (type == 3 && n > 0)
        tail->next = head;
    // Link for circular doubly
    if (type == 4 && n > 0) {
        tail->next = head;
        head->prev = tail;
    }

    cout << "\nRecursive print of linked list:\n";
    // Initial call: pass head as both head and curr, "first" as true
    printList(head, head, type, true);
    cout << endl;

    // Break circle before free (cleanup)
    if ((type == 3 || type == 4) && n > 0)
        tail->next = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    return 0;
}
