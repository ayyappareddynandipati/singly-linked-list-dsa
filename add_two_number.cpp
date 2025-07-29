// Problem: Add Two Numbers represented by Linked Lists
// https://leetcode.com/problems/add-two-numbers/

#include <bits/stdc++.h>
using namespace std;

// Basic singly linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to add two numbers represented by linked lists
Node* addTwoNumbers(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    // Dummy node simplifies result list creation
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    int carry = 0;

    // Traverse both lists
    while (temp1 != nullptr || temp2 != nullptr) {
        int sum = carry;

        // Add current digits (if nodes exist)
        if (temp1) sum += temp1->data;
        if (temp2) sum += temp2->data;

        // Create new node for current digit
        current->next = new Node(sum % 10);
        carry = sum / 10;

        // Move forward
        current = current->next;
        if (temp1) temp1 = temp1->next;
        if (temp2) temp2 = temp2->next;
    }

    // If carry remains, add it
    if (carry) {
        current->next = new Node(carry);
    }

    return dummyNode->next;
}

// Driver code
int main() {
    // Number 1: 999999 (reverse order: 9 -> 9 -> 9 -> 9 -> 9 -> 9)
    Node* head1 = new Node(9, new Node(9, new Node(9, new Node(9, new Node(9, new Node(9))))));

    // Number 2: 999 (reverse order: 9 -> 9 -> 9)
    Node* head2 = new Node(9, new Node(9, new Node(9)));

    // Print both input numbers
    cout << "Input Number 1: ";
    printList(head1);

    cout << "Input Number 2: ";
    printList(head2);

    // Add the two numbers
    Node* result = addTwoNumbers(head1, head2);

    // Print result
    cout << "Result (Sum): ";
    printList(result);

    return 0;
}
