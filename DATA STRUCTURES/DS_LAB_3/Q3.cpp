#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void addFront(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

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
        newNode->prev = temp;
    }

    void deleteNode(int val) {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.addFront(10);
    list.addBack(20);
    list.addFront(5);
    list.deleteNode(20);
    list.printList();
    return 0;
}
