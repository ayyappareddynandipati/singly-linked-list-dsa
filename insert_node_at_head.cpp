// Problem: Insert at Head in a Singly Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Insert new node at head
Node* insertHead(Node* head, int value) {
    return new Node(value, head);
}

// Print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Original linked list: 1 -> 2 -> 3
    Node* head = new Node(1, new Node(2, new Node(3)));

    cout << "Original list: ";
    printList(head);

    // Insert at head (value 0)
    head = insertHead(head, 0);

    cout << "After inserting 0 at head: ";
    printList(head);

    return 0;
}
