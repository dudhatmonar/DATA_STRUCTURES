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

    bool isPalindrome() {
        if (!head || !head->next) return true;
        Node* left = head;
        Node* right = head;
        while (right->next != nullptr) {
            right = right->next;
        }
        while (left != right && right->next != left) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
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
    list.addBack(1);
    list.addBack(2);
    list.addBack(3);
    list.addBack(2);
    list.addBack(1);

    cout << "Linked List: ";
    list.printList();

    if (list.isPalindrome())
        cout << "Palindrome: Yes" << endl;
    else
        cout << "Palindrome: No" << endl;

    return 0;
}
