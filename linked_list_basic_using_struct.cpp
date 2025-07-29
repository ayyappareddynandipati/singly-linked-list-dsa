// Problem: Creating a singly linked list using struct and printing its nodes (data and address)

#include <bits/stdc++.h>
using namespace std;

// Definition of a node using struct
struct Node {
    int data;       // Data value of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize node data and next pointer
    Node(int val, Node* nextPtr = nullptr) {
        data = val;
        next = nextPtr;
    }
};

// Function to print the linked list
void printList(Node* head) {
    cout << "Linked List (Data and Next Node Address):" << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << "Data: " << current->data << ", Next: " << current->next << endl;
        current = current->next;
    }
}

int main() {
    // Creating linked list nodes: 30 -> 20 -> 10
    Node* x = new Node(10);
    Node* y = new Node(20, x);
    Node* z = new Node(30, y);
    Node* head = z;

    // Displaying input linked list
    cout << "Given Input Nodes: 30 -> 20 -> 10" << endl;
    printList(head);

    // Freeing dynamically allocated memory
    delete x;
    delete y;
    delete z;

    return 0;
}
