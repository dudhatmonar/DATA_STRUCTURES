// 4. Check Balanced Parenthesis
// Write a program to check whether a string has balanced parentheses using a stack. A string
// is considered balanced if every opening bracket has a corresponding closing bracket in the
// correct order.
// Examples:
// Input: (A + B) * (C + D)
// Output: Balanced
// Input: (A + B * (C - D)
// Output: Not Balanced

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if brackets are balanced
bool isBalanced(string expr) {
    stack<char> st;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c); // push opening brackets
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false; // no matching opening

            char top = st.top();
            st.pop();

            // Check if it matches
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty(); // stack should be empty if balanced
}

int main() {
    string expr1 = "(A + B) * (C + D)";
    cout << "Input: " << expr1 << endl;
    cout << (isBalanced(expr1) ? "Output: Balanced" : "Output: Not Balanced") << endl;

    string expr2 = "(A + B * (C - D)";
    cout << "Input: " << expr2 << endl;
    cout << (isBalanced(expr2) ? "Output: Balanced" : "Output: Not Balanced") << endl;

    return 0;
}
