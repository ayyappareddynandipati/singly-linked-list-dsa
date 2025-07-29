// Problem: Linked List Cycle II (Start of Cycle)
// https://leetcode.com/problems/linked-list-cycle-ii/
// https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

#include <bits/stdc++.h>
using namespace std;

// Definition of singly-linked list node
struct Node {
    int data;
    Node *next;
    Node(int val, Node *nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Function to find the start node of a cycle if present
Node* startNodeCycle(Node *head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect if a cycle exists using Floyd’s Algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected
        if (slow == fast) {
            // Step 2: Move one pointer to head and move both one step at a time
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Start node of the cycle
        }
    }
    return nullptr; // No cycle found
}

// Helper to safely print limited nodes (to prevent infinite loop if cycle exists)
void printLinkedList(Node* head, int maxNodes = 20) {
    int count = 0;
    while (head != nullptr && count < maxNodes) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
        count++;
    }
    if (count == maxNodes) cout << " ... (stopped, possible cycle)";
    cout << endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    // Creating a cycle: 5 -> 2
    head->next->next->next->next->next = head->next;

    cout << "Input Linked List (first 20 nodes to avoid cycle overflow):" << endl;
    printLinkedList(head);

    cout << "\nFinding start node of cycle in the linked list..." << endl;
    Node* cycleStart = startNodeCycle(head);

    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
