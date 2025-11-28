#include <iostream>
using namespace std;

// Node for SLL
struct Node {
    char data;
    Node* next;
};

// Stack using SLL
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(char x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    // Pop operation
    char pop() {
        if (top == NULL)
            return '\0'; // indicates empty stack
        Node* temp = top;
        char x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }

    // Check empty
    bool isEmpty() {
        return top == NULL;
    }
};

// Function to match pair of brackets
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Balanced bracket function
bool isBalanced(string exp) {

    Stack st;

    for (int i = 0; i < exp.length(); i++) {

        char ch = exp[i];

        // Skip non-bracket characters
        if (ch != '(' && ch != ')' &&
            ch != '{' && ch != '}' &&
            ch != '[' && ch != ']')
            continue;

        // If opening bracket ? push
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        // If closing bracket ? must match
        else {
            if (st.isEmpty())
                return false;  // extra closing bracket

            char open = st.pop();

            if (!isMatchingPair(open, ch))
                return false;  // mismatched pair
        }
    }

    // In the end, stack must be empty
    return st.isEmpty();
}

// Driver code
int main() {
    string exp;

    cout << "Enter expression: ";
    getline(cin, exp);

    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
