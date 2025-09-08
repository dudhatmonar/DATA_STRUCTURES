// 2. Infix to Postfix Conversion
// Write a program to convert an infix expression to a postfix expression using a stack. Infix
// expressions are the standard arithmetic notation (e.g., A + B), whereas postfix expressions
// (Reverse Polish Notation) place operators after operands (e.g., AB+).
// Examples:
// Input: A + B * C
// Output: ABC*+
// Input: (A + B) * C
// Output: AB+C*

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class InfixToPostfix {
public:
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    bool isRightAssociative(char op) {
        return op == '^';
    }

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    string convert(string infix) {
        stack<char> st;
        string postfix = "";

        for (char c : infix) {
            if (c == ' ') continue;
            if (isalnum(c)) {
                postfix += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }
            else if (isOperator(c)) {
                while (!st.empty() && 
                       (precedence(st.top()) > precedence(c) || 
                       (precedence(st.top()) == precedence(c) && !isRightAssociative(c))) &&
                       st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }
};

int main() {
    InfixToPostfix converter;

    string exp1 = "A + B * C - D / E";
    cout << "Input: " << exp1 << endl;
    cout << "Output: " << converter.convert(exp1) << endl;

    string exp2 = "(A + B) * C";
    cout << "Input: " << exp2 << endl;
    cout << "Output: " << converter.convert(exp2) << endl;

    return 0;
}
