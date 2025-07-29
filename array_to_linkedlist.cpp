#include <bits/stdc++.h>
using namespace std;

// Definition for a singly linked list node
struct Node {
    int data;       // Stores the value of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a new node
    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Utility function to convert an array into a linked list
Node* arrayToLinkedList(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    // Create the head node from the first element
    Node* head = new Node(arr[0]);
    Node* current = head;

    // Create remaining nodes and link them
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

// Utility function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    // Convert array to linked list
    Node* head = arrayToLinkedList(arr);

    // Print the linked list before any changes
    cout << "Linked List (Before): ";
    printList(head);

    // Here you can modify the list if needed (currently no changes)

    // Print the linked list after (same as before in this case)
    cout << "Linked List (After): ";
    printList(head);

    return 0;
}
