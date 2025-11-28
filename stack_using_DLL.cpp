#include <iostream>
#include <string>
#include <cctype>

struct DLLNode {
    int data;
    DLLNode *prev;
    DLLNode *next;
    DLLNode(int x) : data(x), prev(NULL), next(NULL) {}
};

class StackDLL {
    DLLNode *top;
public:
    StackDLL() : top(NULL) {}
    ~StackDLL() { clear(); }
    bool isEmpty() { return top == NULL; }
    void push(int x) {
        DLLNode *n = new DLLNode(x);
        n->prev = top;
        if (top) top->next = n;
        top = n;
    }
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow\n";
            return -1;
        }
        int x = top->data;
        DLLNode *temp = top;
        top = top->prev;
        if (top) top->next = NULL;
        delete temp;
        return x;
    }
    int peek() {
        if (isEmpty()) return -1;
        return top->data;
    }
    void clear() {
        while (!isEmpty()) pop();
    }
};

// Helper function to evaluate a postfix expression using DLL stack
int evalPostfix(const std::string &expr, StackDLL &stack) {
    stack.clear();
    int len = expr.length();
    for (int i = 0; i < len; ++i) {
        char c = expr[i];
        if (isspace(c)) continue;
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int b = stack.pop();
            int a = stack.pop();
            switch (c) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
                default: std::cout << "Invalid operator: " << c << "\n";
            }
        }
    }
    return stack.pop();
}

// Helper function to evaluate a prefix expression using DLL stack
int evalPrefix(const std::string &expr, StackDLL &stack) {
    stack.clear();
    int len = expr.length();
    for (int i = len - 1; i >= 0; --i) {
        char c = expr[i];
        if (isspace(c)) continue;
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int a = stack.pop();
            int b = stack.pop();
            switch (c) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
                default: std::cout << "Invalid operator: " << c << "\n";
            }
        }
    }
    return stack.pop();
}

int main() {
    StackDLL stack;
    std::string postfix, prefix;
    std::cout << "Enter postfix expression (e.g. 53+82-*): ";
    std::getline(std::cin, postfix);
    std::cout << "Postfix Evaluation: " << evalPostfix(postfix, stack) << std::endl;

    std::cout << "Enter prefix expression (e.g. -*+5382): ";
    std::getline(std::cin, prefix);
    std::cout << "Prefix Evaluation: " << evalPrefix(prefix, stack) << std::endl;

    return 0;
}
