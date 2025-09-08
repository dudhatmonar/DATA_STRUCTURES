#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

// Convert vector to linked list
ListNode* vectorToList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    return dummy->next;
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

// Swap k-th node from start and k-th node from end
ListNode* swapNodes(ListNode* head, int k) {
    if (!head) return head;

    ListNode* first = head;
    ListNode* second = head;
    ListNode* temp = head;

    int n = 0;

    // Find length of list
    while (temp) {
        n++;
        temp = temp->next;
    }

    // Find k-th node from start
    for (int i = 1; i < k; i++)
        first = first->next;

    // Find k-th node from end
    for (int i = 1; i <= n - k; i++)
        second = second->next;

    // Swap their values
    int t = first->val;
    first->val = second->val;
    second->val = t;

    return head;
}

int main() {
    string line;
    getline(cin, line); // Read node values

    vector<int> nums;
    stringstream ss(line);
    int num;
    while (ss >> num)
        nums.push_back(num);

    int k;
    cin >> k; // Read k

    ListNode* head = vectorToList(nums);
    head = swapNodes(head, k);
    printList(head);

    return 0;
}
