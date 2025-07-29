// https://leetcode.com/problems/copy-list-with-random-pointer/
// https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/

#include <bits/stdc++.h>
using namespace std;

// Structure for a node in the linked list
struct Node {
    int data;
    Node *next, *random;

    // Constructor to initialize a new node
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};

// Function to create a deep copy of a linked list with next and random pointers
Node* cloneLinkedList(Node* head) {
    if (head == NULL)
        return NULL;

    // 1. First Pass: Insert cloned nodes right next to original nodes
    Node* curr = head;
    while (curr != NULL) {
        Node* newNode = new Node(curr->data);  // Create clone node
        newNode->next = curr->next;            // Clone's next is current's next
        curr->next = newNode;                  // Insert clone right after original
        curr = newNode->next;                  // Move to next original node
    }

    // 2. Second Pass: Set the random pointers of cloned nodes
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            // Original node's clone is at curr->next
            // So assign random of clone to curr->random->next (clone of random node)
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;  // Move to next original node
    }

    // 3. Third Pass: Separate original and cloned lists
    curr = head;
    Node* clonedHead = head->next;  // Save the head of the cloned list
    Node* clone = clonedHead;
    while (clone->next != NULL) {
        curr->next = curr->next->next;     // Original node's next restored
        clone->next = clone->next->next;   // Clone's next linked
        curr = curr->next;                 // Move to next original node
        clone = clone->next;               // Move to next cloned node
    }

    // Set tail next pointers to null
    curr->next = NULL;
    clone->next = NULL;

    return clonedHead;  // Return head of deep-copied list
}

// Utility function to print list with random pointers
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << "(";
        if (head->random)
            cout << head->random->data << ")";
        else
            cout << "null)";
        
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating original linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Setting up random links
    head->random = head->next->next;               // 1 → 3
    head->next->random = head;                     // 2 → 1
    head->next->next->random = head->next->next->next->next; // 3 → 5
    head->next->next->next->random = head->next->next;        // 4 → 3
    head->next->next->next->next->random = head->next;        // 5 → 2

    // Print original list
    cout << "Original linked list:\n";
    printList(head);

    // Clone the list
    Node* clonedList = cloneLinkedList(head);

    // Print cloned list
    cout << "Cloned linked list:\n";
    printList(clonedList);

    return 0;
}
