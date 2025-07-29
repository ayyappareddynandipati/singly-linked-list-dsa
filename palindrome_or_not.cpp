// Problem: Check if Linked List is Palindrome
// Leetcode: https://leetcode.com/problems/palindrome-linked-list/
// GFG: https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

#include <bits/stdc++.h>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;

    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Function to reverse a linked list recursively
Node* reverseList(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

// Function to check if a linked list is palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) return true;

    // Step 1: Find the middle of the list using slow-fast pointers
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    Node* secondHalf = reverseList(slow);

    // Step 3: Compare both halves
    Node* firstHalf = head;
    Node* temp = secondHalf;
    bool isPalin = true;
    while (temp != nullptr) {
        if (firstHalf->data != temp->data) {
            isPalin = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    // Step 4: Optional - Restore the original list
    reverseList(secondHalf);

    return isPalin;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Input: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = new Node(1, new Node(2, new Node(3, new Node(2, new Node(1)))));

    cout << "Given Linked List: ";
    printList(head);

    // Check if the list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
