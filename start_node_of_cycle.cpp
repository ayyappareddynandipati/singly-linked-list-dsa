// Problem: Find the start of the cycle in a Linked List
// LeetCode: https://leetcode.com/problems/linked-list-cycle-ii/
// GFG: https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

#include <bits/stdc++.h>
using namespace std;

// Definition of the linked list node
struct Node {
    int data;
    Node* next;
    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Function to detect the start node of the cycle (Floyd’s Cycle Detection Algorithm)
Node* startNodeCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // First step: Detect if a cycle exists
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected
        if (slow == fast) {
            // Move one pointer to head and advance both one step at a time
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Start node of the cycle
        }
    }

    return nullptr; // No cycle detected
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    // Creating a cycle: 5 -> 2
    head->next->next->next->next->next = head->next;

    cout << "Finding start node of cycle in the linked list..." << endl;
    Node* cycleStart = startNodeCycle(head);

    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // ⚠️ Memory cleanup is skipped due to cycle; avoid double deletion

    return 0;
}
