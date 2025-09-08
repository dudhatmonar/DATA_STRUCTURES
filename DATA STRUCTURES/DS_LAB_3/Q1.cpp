#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // 1. Add node in front
    void addFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 2. Add node in back
    void addBack(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3. Delete a node (by value)
    void deleteNode(int val) {
        if (head == nullptr) return;

        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return; // value not found

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // 4. Insert after a given value
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) return; // key not found

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Print the list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Example Input
    list.addBack(10);
    list.addBack(20);
    list.addFront(5);
    list.insertAfter(10, 15);
    list.deleteNode(20);

    // Expected Output
    cout << "Final Linked List: ";
    list.printList();

    return 0;
}
