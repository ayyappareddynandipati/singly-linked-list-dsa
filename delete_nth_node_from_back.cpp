// Problem: Remove Nth Node From End of List
// Leetcode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <bits/stdc++.h>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;

    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Removes the nth node from the end of the linked list
Node* removeNthFromEnd(Node* head, int n) {
    Node* fast = head;

    // Move fast pointer 'n' steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // If fast reaches NULL, we are deleting the first node
    if (fast == nullptr) return head->next;

    Node* slow = head;

    // Move both fast and slow till fast reaches the end
    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the nth node from end
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}

// Utility to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Input: Linked list = 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    int n = 2; // Remove 2nd node from end

    cout << "Original linked list:\n";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "\nLinked list after removing the " << n << "th node from the end:\n";
    printList(head);

    // Clean up the memory
    while (head) {
        Node* delNode = head;
        head = head->next;
        delete delNode;
    }

    return 0;
}
