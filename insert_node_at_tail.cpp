// Problem: Insert at Tail in a Singly Linked List

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

Node* insertTail(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Utility function to print the list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1, new Node(2, new Node(3)));
    int value = 4;

    cout << "Original list: ";
    printList(head);

    head = insertTail(head, value);

    cout << "After inserting " << value << " at tail: ";
    printList(head);

    return 0;
}
