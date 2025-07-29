// Problem: Flattening a Linked List
// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *bottom;
    Node(int newdata) {
        data = newdata;
        next = bottom = nullptr;
    }
};

// Merge two bottom-linked sorted lists
Node* merge(Node* head1, Node* head2) {
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->bottom = head1;
            head1 = head1->bottom;
        } else {
            tail->bottom = head2;
            head2 = head2->bottom;
        }
        tail = tail->bottom;
    }

    if (head1) tail->bottom = head1;
    else tail->bottom = head2;

    return dummy->bottom;
}

// Recursively flatten the list
Node* flatten(Node* root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

// Print the flattened bottom list
void printFlattenedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

// Print the original multi-level list
void printOriginalList(Node* head) {
    cout << "Original linked list (vertical columns via bottom):\n";
    while (head) {
        Node* down = head;
        while (down) {
            cout << down->data << " ";
            down = down->bottom;
        }
        cout << "\n|\n";
        head = head->next;
    }
    cout << "END\n";
}

int main() {
    // Construct the linked list:
    // 5 -> 10 -> 19 -> 28
    // |     |     |
    // 7     20    22
    // |           |
    // 8           50
    // |
    // 30

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    // Print original input
    printOriginalList(head);

    // Flatten the list
    Node* flatHead = flatten(head);

    // Print result
    cout << "\nFlattened linked list:\n";
    printFlattenedList(flatHead);

    return 0;
}
