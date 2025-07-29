// Problem: Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

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

Node* intersectionTwoLists(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) return nullptr;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != temp2) {
        temp1 = (temp1 == nullptr) ? head2 : temp1->next;
        temp2 = (temp2 == nullptr) ? head1 : temp2->next;
    }

    return temp1;  // May be nullptr if no intersection
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Shared tail
    Node* common = new Node(8, new Node(10));

    // First list: 3 -> 6 -> 9 -> 8 -> 10
    Node* head1 = new Node(3, new Node(6, new Node(9, common)));

    // Second list: 10 -> 8 -> 10
    Node* head2 = new Node(10, new Node(8, common));

    // Print input lists
    cout << "First Linked List: ";
    printList(head1);
    cout << "Second Linked List: ";
    printList(head2);

    // Find intersection
    Node* intersection = intersectionTwoLists(head1, head2);

    // Output result
    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
