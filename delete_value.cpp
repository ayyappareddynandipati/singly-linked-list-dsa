// Problem: Delete node with given value from singly linked list

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

Node* deleteValue(Node* head, int value) {
    if (head == nullptr) return nullptr;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->data == value) {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            delete current;
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;  // Value not found, return unmodified head
}

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
    Node* head = new Node(1, new Node(2, new Node(3)));

    cout << "Original list:\n";
    printList(head);

    int valueToDelete = 2;
    head = deleteValue(head, valueToDelete);

    cout << "\nList after deleting value " << valueToDelete << ":\n";
    printList(head);

    // Cleanup
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
