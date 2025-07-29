// Problem: Reverse a Singly Linked List (Recursive Approach)
// Source: LeetCode / GFG
#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list node
struct Node {
    int data;
    Node* next;

    // Constructor with default next as nullptr
    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Recursive function to reverse a linked list
Node* reverseList(Node* head) {
    // Base case: empty list or only one node
    if (head == nullptr || head->next == nullptr)
        return head;

    // Recursively reverse the rest of the list
    Node* newHead = reverseList(head->next);

    // Change next pointers to reverse current node
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    // Print original linked list
    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    // Print reversed linked list
    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
