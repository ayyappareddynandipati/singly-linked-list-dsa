// Problem: Reverse Nodes in K-Group (LeetCode: https://leetcode.com/problems/reverse-nodes-in-k-group/)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node class represents each node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Helper function to reverse a linked list using three pointers
Node* reverseLinkedList(Node *head) {
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

// Function to get the k-th node from the current node
Node* getKthNode(Node* temp, int k){
    k -= 1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp -> next;
    }
    return temp;
}

// Function to reverse nodes in groups of size k
Node* kReverse(Node* head, int k){
    Node* temp = head;
    Node* prevLast = NULL;

    while(temp != NULL){
        Node* kThNode = getKthNode(temp, k);
        if(kThNode == NULL){
            if(prevLast){
                prevLast -> next = temp;
            }
            break;
        }

        Node* nextNode = kThNode -> next;
        kThNode -> next = NULL;

        reverseLinkedList(temp);

        if(temp == head){
            head = kThNode;
        } else {
            prevLast -> next = kThNode;
        }

        prevLast = temp;
        temp = nextNode;
    }

    return head;
}

// Utility function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Utility function to copy and print the input list before modification
void printOriginalInput(Node* head) {
    cout << "Given Input List: ";
    printLinkedList(head);
}

int main() {
    // Creating the linked list: 5 -> 4 -> 3 -> 7 -> 9 -> 2
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Print the given inputs
    printOriginalInput(head);

    // Reverse nodes in groups of 4
    head = kReverse(head, 4);

    // Print the modified list after k-group reversal
    cout << "Output List after Reversing in K-Groups: ";
    printLinkedList(head);

    return 0;
}
