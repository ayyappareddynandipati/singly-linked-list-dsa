// Problem: Find the Middle of a Linked List (Tortoise-Hare Method)
// Link: https://leetcode.com/problems/middle-of-the-linked-list/

#include <bits/stdc++.h>
using namespace std;

// Node definition for singly linked list
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to find the middle element of the linked list
int getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Move fast pointer two steps and slow pointer one step
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // When fast reaches end, slow will be at the middle
    return slow->data;
}

// Utility function to print a linked list
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Print the input linked list
    cout << "Given Linked List: ";
    printList(head);

    // Call the function and print the middle element
    cout << "Middle element is: " << getMiddle(head) << endl;

    // Free the allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
