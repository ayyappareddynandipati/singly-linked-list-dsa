// Problem: Detect Cycle in Linked List
// https://leetcode.com/problems/linked-list-cycle/
// https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    // Given input
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    // Creating a cycle: Node 5 points to Node 2
    head->next->next->next->next->next = head->next;

    cout << "Linked list contains: 1 -> 2 -> 3 -> 4 -> 5 (with a cycle: 5 -> 2)" << endl;

    // Output
    if (hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // ⚠️ Memory cleanup not safe here due to cycle

    return 0;
}
