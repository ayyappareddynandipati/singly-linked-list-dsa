// Problem: Delete Middle Node of a Linked List
// GFG: https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1
// Leetcode: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Deletes the middle node of the linked list and returns updated head
Node* deleteMid(Node* head) {
    // If list has 0 or 1 node, nothing to delete
    if (head == nullptr || head->next == nullptr)
        return head;

    // Initialize slow and fast pointers
    Node* slow = head;
    Node* fast = head;

    // Move fast by two and slow by one to find middle
    fast = fast->next->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the node after slow (which is the middle one)
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}

// Utility function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original linked list:\n";
    printList(head);

    head = deleteMid(head);

    cout << "\nLinked list after deleting the middle node:\n";
    printList(head);

    // Free memory
    while (head) {
        Node* delNode = head;
        head = head->next;
        delete delNode;
    }

    return 0;
}
