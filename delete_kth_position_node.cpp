// Problem: Delete K-th Node from a Singly Linked List

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Deletes the k-th node (1-based indexing) from the list
Node* deleteK(Node* head, int k) {
    if (head == nullptr || k <= 0) return head;

    // Special case: delete the head node
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    Node* prev = nullptr;
    int count = 0;

    // Traverse to the k-th node
    while (current != nullptr) {
        count++;
        if (count == k) {
            if (prev) prev->next = current->next;
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }

    return head;
}

// Utility function to print linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1 -> 2 -> 3
    Node* head = new Node(1, new Node(2, new Node(3)));
    int k = 2;

    cout << "Original List:\n";
    printList(head);  // Print list before deletion

    head = deleteK(head, k);  // Delete k-th node

    cout << "\nList after deleting " << k << "-th node:\n";
    printList(head);  // Print result

    return 0;
}
