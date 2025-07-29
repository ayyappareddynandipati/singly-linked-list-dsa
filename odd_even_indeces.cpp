// Problem: Rearrange Linked List - Odd Even Position Nodes
// Leetcode: https://leetcode.com/problems/odd-even-linked-list/
// GFG: https://www.geeksforgeeks.org/problems/rearrange-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

// Definition of a node in the singly linked list
struct Node {
    int data;
    Node* next;

    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Function to rearrange the linked list so that all odd-positioned nodes
// come before even-positioned nodes, preserving their original order.
Node* evenOdd(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    // Traverse and separate odd and even nodes
    while (even != nullptr && even->next != nullptr) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    // Join even list after odd list
    odd->next = evenHead;
    return head;
}

// Utility function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Input: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    cout << "Given Linked List: ";
    printList(head);

    // Rearrange the list as per odd-even positioning
    head = evenOdd(head);

    cout << "After Rearranging (Odd-Even Positions): ";
    printList(head);

    return 0;
}
