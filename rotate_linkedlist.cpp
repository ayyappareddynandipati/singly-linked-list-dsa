// Problem: Rotate a Linked List
// Leetcode: https://leetcode.com/problems/rotate-list/
// GFG: https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Function to get the k-th node from the start (1-based indexing)
Node* kthNode(Node* temp, int k) {
    int cnt = 1;
    while (temp != nullptr) {
        if (cnt == k) return temp;
        temp = temp->next;
        cnt++;
    }
    return nullptr; // If k > length
}

// Function to rotate the linked list to the right by k places
Node* rotateLinkedList(Node* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) return head;

    // Step 1: Find tail and count length
    Node* tail = head;
    int length = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }

    // Step 2: Handle rotations greater than length
    k = k % length;
    if (k == 0) return head;

    // Step 3: Make it circular and break at new position
    tail->next = head; // Form circular list
    Node* newTail = kthNode(head, length - k);
    Node* newHead = newTail->next;
    newTail->next = nullptr; // Break the loop

    return newHead;
}

// Utility function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Input linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    int k = 2; // Number of positions to rotate

    // Print original input
    cout << "Original Linked List: ";
    printList(head);
    cout << "Rotation Count (k): " << k << endl;

    // Rotate the linked list
    Node* rotatedHead = rotateLinkedList(head, k);

    // Print rotated list
    cout << "Linked List After Rotating by " << k << " Positions: ";
    printList(rotatedHead);

    return 0;
}
