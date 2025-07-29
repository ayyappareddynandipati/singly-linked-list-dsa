// Problem: Delete Head Node in a Singly Linked List

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

// Deletes the head node and returns the new head
Node* deletehead(Node* head) {
    if (head == nullptr) return nullptr;  // If list is empty, return nullptr

    Node* temp = head;    // Store current head
    head = head->next;    // Move head to next node
    delete temp;          // Free memory of old head
    return head;
}

// Utility to print linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create initial linked list: 1 -> 2 -> 3
    Node* head = new Node(1, new Node(2, new Node(3)));

    cout << "Original List:\n";
    printList(head);  // Print before deletion

    head = deletehead(head);  // Delete head node

    cout << "\nList after deleting head:\n";
    printList(head);  // Print after deletion

    return 0;
}
