// Problem: Creating and printing a simple linked list with data and next pointers

#include <bits/stdc++.h>
using namespace std;

// Definition of a Node in the linked list
class Node {
public:
    int data;       // Holds the data value
    Node* next;     // Pointer to the next node

    // Constructor to initialize data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Function to print the linked list
void printList(Node* head) {
    cout << "Linked List (data and next address):" << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << "Data: " << current->data << ", Next: " << current->next << endl;
        current = current->next;
    }
}

int main() {
    // Creating individual nodes
    Node* x = new Node(10, nullptr);
    Node* y = new Node(20, x);
    Node* z = new Node(30, y);

    // Setting head to point to the first node
    Node* head = z;

    // Print the original linked list
    cout << "Given Input Nodes: 30 -> 20 -> 10" << endl;
    printList(head);

    return 0;
}
