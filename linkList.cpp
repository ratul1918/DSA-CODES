#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
typedef struct Node {
    int data; 
    struct Node* prev; // Pointer to previous node.
    struct Node* next; // Pointer to next node.
} Node;

// Global head and tail pointers. 
Node* head = NULL;
Node* tail = NULL;

// Function to insert a node at the beginning of the list
void insertFirst(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode; // Link previous head back to new node
    else
        tail = newNode; // If list was empty, new node is also the tail

    head = newNode; // Update head
}

// Function to insert a node at the end of the list
void insertLast(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL)
        tail->next = newNode; // Link previous tail to new node
    else
        head = newNode; // If list was empty, new node is also the head

    tail = newNode; // Update tail
}

// Function to insert a node at a specific position (1-based index)
void insertAtPosition(int position, int value) {
    if (position <= 0) return; // Invalid position

    if (position == 1) {
        insertFirst(value); // Insert at the beginning
        return;
    }

    Node* temp = head;
    // Traverse to the node just before the desired position
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        // Position is beyond current list length; insert at end
        insertLast(value);
    } else {
        // Insert in the middle
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;

        if (newNode->next == NULL)
            tail = newNode; // Update tail if inserted at the end
    }
}

// Function to delete the first node
void deleteFirst() {
    if (head == NULL) return; // Empty list

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL; // Remove backward link
    else
        tail = NULL; // List becomes empty

    free(temp); // Free removed node
}

// Function to delete the last node
void deleteLast() {
    if (tail == NULL) return; // Empty list

    Node* temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL; // Remove forward link
    else
        head = NULL; // List becomes empty

    free(temp); // Free removed node
}
