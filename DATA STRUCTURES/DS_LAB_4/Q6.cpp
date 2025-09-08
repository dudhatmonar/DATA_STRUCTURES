// 6. Find the Middle Element of the Linked List
// Write a program to find the middle element of a singly linked list. If the number of elements
// is even, return the second middle element.
// Examples:
// Input: 1 -> 2 -> 3 -> 4 -> 5
// Output: 3
// Input: 10 -> 20 -> 30 -> 40
// Output: 30

// Instructions:
// 1. Do not use ChatGPT or other AI tools to generate the code.
// 2. Write the code yourself to understand the concepts better.
// 3. Include any references or links you used to complete the assignment at the end of your
// submission.


#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Append node at end
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // Display linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Find middle element
    int findMiddle() {
        if (!head) return -1; // empty list

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data; // slow points to middle (second middle if even)
    }
};

int main() {
    LinkedList list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    list1.append(4);
    list1.append(5);

    cout << "Input: ";
    list1.display();
    cout << "Middle Element: " << list1.findMiddle() << endl;

    LinkedList list2;
    list2.append(10);
    list2.append(20);
    list2.append(30);
    list2.append(40);

    cout << "Input: ";
    list2.display();
    cout << "Middle Element: " << list2.findMiddle() << endl;

    return 0;
}
