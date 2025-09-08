// 1. Implement the program of Stack
// Write a program to implement a stack data structure. The stack should be able to perform
// the following operations:
// - Push: Insert an element
// - Pop: Remove the top element
// - Peek (Top): View the top element without removing it
// - Size: Return the number of elements in the stack
// - isEmpty: Check whether the stack is empty
// Examples:
// Input: Push(10), Push(20), Pop(), Peek()
// Output: Stack after push: [10,20], After pop: [10], Peek: 10
// Input: isEmpty(), Size()
// Output: False, 1

#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> arr;
public:
    void push(int val) {
        arr.push_back(val);
        cout << "Stack after push: [";
        display();
        cout << "]\n";
    }

    void pop() {
        if (arr.empty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        arr.pop_back();
        cout << "Stack after pop: [";
        display();
        cout << "]\n";
    }

    void peek() {
        if (arr.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Peek: " << arr.back() << "\n";
    }

    void size() {
        cout << "Size: " << arr.size() << "\n";
    }

    void isEmpty() {
        cout << (arr.empty() ? "True" : "False") << "\n";
    }

    void display() {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ",";
        }
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.pop();
    st.peek();
    st.isEmpty();
    st.size();
    return 0;
}
