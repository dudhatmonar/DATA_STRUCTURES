// 5. Doubly Circular Linked List
// Write a program to implement a doubly circular linked list. The list should allow insertion,
// deletion, and traversal in both forward and backward directions. Each node will have links
// to both its previous and next nodes, and the last node should link back to the first node to
// form a circle.

// Examples:
// Input: Insert 10, Insert 20, Insert 30
// Output: Forward: 10 -> 20 -> 30 -> 10, Backward: 30 -> 20 -> 10 -> 30
// Input: Delete 20
// Output: Forward: 10 -> 30 -> 10, Backward: 30 -> 10 -> 30


#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

// Doubly Circular Linked List
class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    // Delete a node by value
    void remove(int val) {
        if (!head) return;

        Node* curr = head;
        Node* toDelete = NULL;

        // Traverse the circular list
        do {
            if (curr->data == val) {
                toDelete = curr;
                break;
            }
            curr = curr->next;
        } while (curr != head);

        if (!toDelete) return; // not found

        if (toDelete->next == toDelete) { // only one node
            head = NULL;
        } else {
            Node* prevNode = toDelete->prev;
            Node* nextNode = toDelete->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            if (toDelete == head) head = nextNode;
        }
        delete toDelete;
    }

    // Forward traversal
    void displayForward() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "Forward: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // complete circle
    }

    // Backward traversal
    void displayBackward() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* tail = head->prev;
        Node* temp = tail;
        cout << "Backward: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->prev;
        } while (temp != tail);
        cout << tail->data << endl; // complete circle
    }
};

int main() {
    DoublyCircularLinkedList list;

    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.displayForward();   // 10 -> 20 -> 30 -> 10
    list.displayBackward();  // 30 -> 20 -> 10 -> 30

    // Delete element
    list.remove(20);
    list.displayForward();   // 10 -> 30 -> 10
    list.displayBackward();  // 30 -> 10 -> 30

    return 0;
}
