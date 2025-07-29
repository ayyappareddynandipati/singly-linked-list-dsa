// Problem: Insert at K-th Node in a Singly Linked List

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

Node* insertAtKthNode(Node* head, int k, int value) {
    if (k <= 0) return head;

    if (head == nullptr) {
        if (k == 1) return new Node(value);
        else return head; // invalid position
    }

    if (k == 1) {
        return new Node(value, head); // insert at head
    }

    int cnt = 1;
    Node* current = head;
    while (current != nullptr) {
        if (cnt == k - 1) {
            Node* temp = new Node(value, current->next);
            current->next = temp;
            break;
        }
        cnt++;
        current = current->next;
    }

    return head;
}

// Function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1, new Node(2, new Node(3)));
    int k = 2;       // Position to insert the new node
    int value = 4;   // Value of the new node

    cout << "Original list: ";
    printList(head);

    head = insertAtKthNode(head, k, value);

    cout << "After inserting " << value << " at position " << k << ": ";
    printList(head);

    return 0;
}
