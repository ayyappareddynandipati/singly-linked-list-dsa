// Problem: Insert Before a Node with Given Value in a Singly Linked List

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

Node* insertAtValue(Node* head, int value, int element) {
    if (head == nullptr) {
        return head;
    }

    // Insertion at head if match is at head
    if (head->data == value) {
        return new Node(element, head);
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == value) {
            Node* newNode = new Node(element, current->next);
            current->next = newNode;
            return head;
        }
        current = current->next;
    }

    // If value not found, return list as-is
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1, new Node(2, new Node(4)));
    int value = 4;     // Insert before node with this value
    int element = 3;   // New node value to insert

    cout << "Original list: ";
    printList(head);

    head = insertAtValue(head, value, element);

    cout << "After inserting " << element << " before " << value << ": ";
    printList(head);

    return 0;
}
