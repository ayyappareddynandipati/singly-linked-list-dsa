// Problem: Find Y Intersection Point of Two Linked Lists
// GFG: https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
// LeetCode: https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to get length of linked list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection node
Node* getIntersectionNode(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Make sure head1 is always the longer list
    if (len2 > len1) swap(head1, head2);

    // Advance the pointer of longer list by the difference
    while (diff--) {
        head1 = head1->next;
    }

    // Move both pointers together until they meet
    while (head1 && head2) {
        if (head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr; // No intersection
}

// Function to print list from a given node
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Common part of the Y-shaped list: 8 -> 10
    Node* common = new Node(8);
    common->next = new Node(10);

    // First list: 3 -> 6 -> 9 -> [8 -> 10]
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common;

    // Second list: 4 -> 5 -> [8 -> 10]
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    Node* intersection = getIntersectionNode(head1, head2);
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    // ⚠️ Memory cleanup skipped for simplicity as nodes are shared

    return 0;
}
