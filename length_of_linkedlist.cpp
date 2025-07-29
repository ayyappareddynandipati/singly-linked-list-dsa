// Problem: Find Length of a Singly Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val, Node* nextval = nullptr) {
        data = val;
        next = nextval;
    }
};

// Function to calculate the length of the linked list
int length_of_linkedlist(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// Helper function to print the list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    cout << "Input linked list: ";
    printList(head);

    cout << "Length of linked list: " << length_of_linkedlist(head) << endl;

    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
