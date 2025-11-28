#include <iostream>
#include <string>
#include <cctype>

class StackArray {
    int *arr;
    int top, capacity;
public:
    StackArray(int n) : capacity(n), top(-1) {
        arr = new int[n];
    }
    ~StackArray() {
        delete[] arr;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
    void push(int x) {
        if (!isFull()) arr[++top] = x;
        else std::cout << "Stack overflow\n";
    }
    int pop() {
        if (!isEmpty()) return arr[top--];
        else {
            std::cout << "Stack underflow\n";
            return -1;
        }
    }
    int peek() {
        if (!isEmpty()) return arr[top];
        else return -1;
    }
    void clear() {
        top = -1;
    }
};

// Helper function to evaluate a postfix expression (C++98 compatible)
int evalPostfix(const std::string &expr, StackArray &stack) {
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

// Helper function to evaluate a prefix expression (C++98 compatible)
int evalPrefix(const std::string &expr, StackArray &stack) {
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
    StackArray stack(100);
    std::string postfix, prefix;
    std::cout << "Enter postfix expression (e.g. 53+82-*): ";
    std::getline(std::cin, postfix);
    std::cout << "Postfix Evaluation: " << evalPostfix(postfix, stack) << std::endl;

    std::cout << "Enter prefix expression (e.g. -+53*82): ";
    std::getline(std::cin, prefix);
    std::cout << "Prefix Evaluation: " << evalPrefix(prefix, stack) << std::endl;

    return 0;
}
