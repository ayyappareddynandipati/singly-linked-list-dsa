// Problem: Search for a Node in a Singly Linked List
// Description: Return the node containing the target value, or nullptr if not found.

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

// Function to search for a value in the linked list
Node* search_node_in_linkedlist(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return current; // Target found
        }
        current = current->next;
    }
    return nullptr; // Not found
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    // Set the target value to search
    int target = 3;

    // Print the input list and target
    cout << "Input Linked List: ";
    printList(head);
    cout << "Searching for value: " << target << endl;

    // Perform search
    Node* result = search_node_in_linkedlist(head, target);
    
    // Output result
    if (result != nullptr) {
        cout << "Node with value " << target << " found at address: " << result << endl;
    } else {
        cout << "Node with value " << target << " not found in the list." << endl;
    }

    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
