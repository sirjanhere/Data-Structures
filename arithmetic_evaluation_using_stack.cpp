#include <iostream>
using namespace std;

// Stack for characters (operators)
class CharStack {
public:
    char arr[100];
    int top;

    CharStack() { top = -1; }

    void push(char x) {
        arr[++top] = x;
    }

    char pop() {
        return arr[top--];
    }

    char peek() {
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};

// Stack for integers (operands during evaluation)
class IntStack {
public:
    int arr[100];
    int top;

    IntStack() { top = -1; }

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    bool empty() {
        return top == -1;
    }
};

// Function to check if character is operator
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

// Precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Convert Infix ? Postfix using stack
string infixToPostfix(string exp) {
    CharStack st;
    string postfix = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // Skip spaces
        if (c == ' ') 
            continue;

        // If digit ? add to postfix
        if (isdigit(c)) {
            postfix += c;
        }

        // If '(' push it
        else if (c == '(') {
            st.push(c);
        }

        // If ')' pop until '('
        else if (c == ')') {
            while (!st.empty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop(); // remove '('
        }

        // If operator
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.peek()) >= precedence(c)) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.pop();
    }

    return postfix;
}

// Evaluate postfix expression using integer stack
int evaluatePostfix(string postfix) {
    IntStack st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If digit ? push to stack
        if (isdigit(c)) {
            st.push(c - '0');   // convert char to int
        }
        // If operator ? pop two numbers and apply op
        else if (isOperator(c)) {
            int b = st.pop();
            int a = st.pop();
            int result;

            switch(c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': {
                    result = 1;
                    for (int k = 0; k < b; k++)
                        result *= a;
                    break;
                }
            }
            st.push(result);
        }
    }
    return st.pop();
}

int main() {
    string exp;

    cout << "Enter an arithmetic expression: ";
    getline(cin, exp);

    // Step 1: Convert to postfix
    string postfix = infixToPostfix(exp);
    cout << "Postfix Expression: " << postfix << endl;

    // Step 2: Evaluate postfix
    int answer = evaluatePostfix(postfix);
    cout << "Result: " << answer << endl;

    return 0;
}
