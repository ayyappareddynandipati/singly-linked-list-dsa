// Problem: Reverse a Singly Linked List (Iterative Approach)
// Source: LeetCode / GFG

#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list node
struct Node {
    int data;
    Node* next;

    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Iterative function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next; // Store next node
        current->next = prev;           // Reverse current node's pointer
        prev = current;                 // Move prev and current one step forward
        current = nextNode;
    }

    return prev; // New head after reversal
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    // Print original list
    cout << "Original Linked List: ";
    printList(head);

    // Reverse using iterative approach
    head = reverseList(head);

    // Print reversed list
    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
