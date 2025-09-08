#include <iostream>
#include <string>
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

    // Add node at back
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

    // Delete first N nodes
    void deleteFirstN(int n) {
        while (head != nullptr && n > 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            n--;
        }
    }

    // Calculate sum of all nodes
    int sumNodes() {
        int sum = 0;
        Node* temp = head;
        while (temp != nullptr) {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    // Print the linked list
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
    string studentID;

    cout << "Enter Student ID: ";
    cin >> studentID;

    // Step 1: Add each digit of Student ID into the list
    for (char c : studentID) {
        list.addBack(c - '0');  // convert char to int
    }

    cout << "Original Linked List: ";
    list.printList();

    // Step 2: Delete first 3 nodes
    list.deleteFirstN(3);

    cout << "After deleting first 3 nodes: ";
    list.printList();

    // Step 3: Print sum of remaining nodes
    cout << "Sum = " << list.sumNodes() << endl;

    return 0;
}
