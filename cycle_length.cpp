// Problem: Find Length of Loop in Linked List
// GFG: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node *next;

    // Constructor with default next pointer as nullptr
    Node(int val, Node *nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Function to detect and return length of cycle in the list
int cycleLength(Node *head) {
    Node* slow = head;
    Node* fast = head;

    // Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare)
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps

        // If both pointers meet, there is a cycle
        if (slow == fast) {
            int cnt = 1;
            fast = fast->next;

            // Count the number of nodes in the loop
            while (fast != slow) {
                cnt++;
                fast = fast->next;
            }

            return cnt;  // return length of cycle
        }
    }

    // If no cycle is found, return 0
    return 0;
}

// Utility to print first few elements (since list is cyclic)
void printLimitedList(Node* head, int limit = 10) {
    Node* current = head;
    int count = 0;
    while (current != nullptr && count < limit) {
        cout << current->data;
        current = current->next;
        if (current != nullptr) cout << " -> ";
        count++;
    }
    if (current != nullptr) cout << " -> ... (cycle continues)";
    cout << endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    // Creating a cycle: 5 -> 2 (connect tail to second node)
    head->next->next->next->next->next = head->next;

    cout << "Given Linked List with possible cycle (first 10 nodes printed):\n";
    printLimitedList(head);

    int length = cycleLength(head);

    cout << "\nCycle length is: " << length << endl;

    return 0;
}
