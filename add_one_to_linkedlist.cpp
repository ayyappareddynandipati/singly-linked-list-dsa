// Problem: Add 1 to a number represented as a linked list
// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include <bits/stdc++.h>
using namespace std;

// Basic structure of a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val, Node* nextNode = nullptr) {
        data = val;
        next = nextNode;
    }
};

// Recursive helper function to perform the actual addition
int Helper(Node* head) {
    // Base case: if we've reached beyond the last node, return carry = 1
    if (head == nullptr) {
        return 1; // Starting the +1 operation from the least significant digit
    }

    // Recurse to the end of the list
    int carry = Helper(head->next);

    // Add carry to current node’s data
    int sum = head->data + carry;

    // Update current node’s value to the last digit of sum
    head->data = sum % 10;

    // Return carry for the previous node (1 if sum >= 10, else 0)
    return sum / 10;
}

// Function to add one to the number represented by the linked list
Node* addOneToNumber(Node* head) {
    int carry = Helper(head);  // Start recursive addition from the end

    // If carry is left after processing all nodes, add a new node at the beginning
    if (carry > 0) {
        Node* newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }

    return head;  // Return the updated head of the list
}

// Utility function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code to test the logic
int main() {
    // Creating a number: 999999 (which will become 1000000 after adding 1)
    Node* head = new Node(9, new Node(9, new Node(9, new Node(9, new Node(9, new Node(9))))));
    
    cout << "Before adding 1: ";
    printList(head);

    // Perform addition
    Node* newNode = addOneToNumber(head);

    cout << "After adding 1: ";
    printList(newNode);

    return 0;
}
