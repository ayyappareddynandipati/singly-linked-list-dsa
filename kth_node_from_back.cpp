// Problem: Nth Node from End of Linked List
// GFG: https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to find the data of the k-th node from the end
int getKthFromLast(Node* head, int k) {
    Node* fast = head;

    // Move 'fast' pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) return -1; // k is larger than length
        fast = fast->next;
    }

    // If fast becomes null here, kth node from end is head
    if (fast == nullptr) return head->data;

    Node* slow = head;

    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

// Utility to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Sample input: 1 -> 2 -> 3 -> 4 -> 5, k = 2
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;

    cout << "Original Linked List: ";
    printList(head);

    int result = getKthFromLast(head, k);
    cout << k << "th node from the end is: " << result << endl;

    // Cleanup
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
