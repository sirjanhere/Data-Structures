#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int prec(char c) {
    if (c=='^') return 3;
    if (c=='*' || c=='/') return 2;
    if (c=='+' || c=='-') return 1;
    return 0;
}

string infixToPostfix(string s, bool forPrefix=false) {
    stack<char> st;
    string out = "";

    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c == ' ') continue;

        if (isalnum(c)) {
            out += c;
        }
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                out += st.top(); st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (isOperator(c)) {

            if (!forPrefix) {
                // Normal postfix popping rule
                while (!st.empty() && isOperator(st.top()) &&
                       ((prec(st.top()) > prec(c)) ||
                        (prec(st.top()) == prec(c) && c != '^'))) 
                {
                    out += st.top();
                    st.pop();
                }
            }
            else {
                // PREFIX MODE: strict > only
                while (!st.empty() && isOperator(st.top()) &&
                       (prec(st.top()) > prec(c))) 
                {
                    out += st.top();
                    st.pop();
                }
            }

            st.push(c);
        }
    }

    while (!st.empty()) {
        out += st.top();
        st.pop();
    }

    return out;
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    string postfix = infixToPostfix(s, true);

    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int evalPostfix(string s) {
    stack<int> st;

    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c == ' ') continue;

        if (isdigit(c)) {
            st.push(c - '0');          // single-digit operands
        }
        else if (isOperator(c)) {
            // safety: need two operands
            if ((int)st.size() < 2) {
                cout << "Error: Malformed postfix expression (not enough operands for operator '" 
                     << c << "').\n";
                return 0;
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') {
                if (b == 0) {
                    cout << "Error: Division by zero\n";
                    return 0;
                }
                st.push(a / b);
            }
            else if (c == '^') {
                int r = 1;
                for (int k = 0; k < b; ++k) r *= a;
                st.push(r);
            }
        }
        else {
            cout << "Error: Invalid character '" << c << "' in expression.\n";
            return 0;
        }
    }

    if (st.empty()) {
        cout << "Error: Empty or malformed postfix expression.\n";
        return 0;
    }
    if (st.size() > 1) {
        cout << "Error: Malformed postfix expression (extra operands remain).\n";
        return 0;
    }
    return st.top();
}

int evalPrefix(string s) {
    stack<int> st;

    for (int i = (int)s.size() - 1; i >= 0; i--) {
        char c = s[i];
        if (c == ' ') continue;

        if (isdigit(c)) {
            st.push(c - '0');          // single-digit operands
        }
        else if (isOperator(c)) {
            if ((int)st.size() < 2) {
                cout << "Error: Malformed prefix expression (not enough operands for operator '"
                     << c << "').\n";
                return 0;
            }
			int a = st.top(); st.pop();   // first popped = left operand
			int b = st.top(); st.pop();   // second popped = right operand

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') {
                if (b == 0) {
                    cout << "Error: Division by zero\n";
                    return 0;
                }
                st.push(a / b);
            }
            else if (c == '^') {
                int r = 1;
                for (int k = 0; k < b; ++k) r *= a;
                st.push(r);
            }
        }
        else {
            cout << "Error: Invalid character '" << c << "' in expression.\n";
            return 0;
        }
    }

    if (st.empty()) {
        cout << "Error: Empty or malformed prefix expression.\n";
        return 0;
    }
    if (st.size() > 1) {
        cout << "Error: Malformed prefix expression (extra operands remain).\n";
        return 0;
    }
    return st.top();
}


int main() {
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Convert Infix to Prefix\n";
        cout << "3. Evaluate Prefix Expression\n";
        cout << "4. Evaluate Postfix Expression\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        int ch;
        cin >> ch;
        cin.ignore();

        if (ch == 0) break;

        string exp;
        cout << "Enter expression (spaces allowed): ";
        getline(cin, exp);

        if (ch == 1) cout << "Postfix: " << infixToPostfix(exp) << "\n";
        else if (ch == 2) cout << "Prefix: " << infixToPrefix(exp) << "\n";
        else if (ch == 3) cout << "Result: " << evalPrefix(exp) << "\n";
        else if (ch == 4) cout << "Result: " << evalPostfix(exp) << "\n";
        else cout << "Invalid option\n";
    }
}
