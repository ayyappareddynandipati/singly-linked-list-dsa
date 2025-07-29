// Problem: Sort 0s, 1s, and 2s in a Linked List
// Source: Similar to https://leetcode.com/problems/sort-list/ or custom variation

#include <bits/stdc++.h>
using namespace std;

// Structure of a node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to sort the linked list containing only 0s, 1s, and 2s
Node* sortZeroesOnesTwos(Node* head) {
    if (!head || !head->next) return head;

    // Dummy nodes for three separate lists: 0s, 1s, and 2s
    Node *zeroHead = new Node(0), *oneHead = new Node(0), *twoHead = new Node(0);
    Node *zeroTail = zeroHead, *oneTail = oneHead, *twoTail = twoHead;

    // Traverse the list and distribute nodes into three lists
    Node* current = head;
    while (current) {
        if (current->data == 0) {
            zeroTail->next = current;
            zeroTail = zeroTail->next;
        } else if (current->data == 1) {
            oneTail->next = current;
            oneTail = oneTail->next;
        } else {
            twoTail->next = current;
            twoTail = twoTail->next;
        }
        current = current->next;
    }

    // Link the three lists together in order: 0s -> 1s -> 2s
    zeroTail->next = oneHead->next ? oneHead->next : twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = nullptr;

    // Determine the new head of the sorted list
    Node* sortedHead = zeroHead->next ? zeroHead->next : (oneHead->next ? oneHead->next : twoHead->next);

    // Free the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return sortedHead;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Creating input list: 1 -> 0 -> 1 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Print the original list
    cout << "Original linked list: ";
    printList(head);

    // Sort the list
    head = sortZeroesOnesTwos(head);

    // Print the sorted list
    cout << "Sorted linked list: ";
    printList(head);

    // Free allocated memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
