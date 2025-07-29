// Problem: Delete Last Node in Singly Linked List

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

// Deletes the last (tail) node of the linked list
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;       // delete the last node
    temp->next = nullptr;    // set second last node's next to nullptr
    return head;
}

// Utility to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create input linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4))));

    cout << "Original linked list:\n";
    printList(head);

    head = deleteTail(head);

    cout << "\nLinked list after deleting the last node:\n";
    printList(head);

    // Cleanup memory
    while (head) {
        Node* del = head;
        head = head->next;
        delete del;
    }

    return 0;
}