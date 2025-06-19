#include <stdio.h>
#include <stdlib.h>

// Structure of a Doubly Linked List node...
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

// Insert at the beginning..
void insertFirst(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode; // If list was empty

    head = newNode;
}

// Insert at the end
void insertLast(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode; // If list was empty

    tail = newNode;
}

// Insert at a specific position
void insertAtPosition(int position, int value) {
    if (position <= 0) return;

    if (position == 1) {
        insertFirst(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        insertLast(value);
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;

        if (newNode->next == NULL)
            tail = newNode;
    }
}

// Delete the first node
void deleteFirst() {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}

// Delete the last node
void deleteLast() {
    if (tail == NULL) return;

    Node* temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}

// Display list
void displayList() {
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test all operations
int main() {
    insertFirst(30);
    insertFirst(20);
    insertFirst(10);     // List: 10 20 30

    displayList();

    insertLast(40);
    insertLast(50);      // List: 10 20 30 40 50

    displayList();

    insertAtPosition(3, 25); // List: 10 20 25 30 40 50

    displayList();

    deleteFirst();       // List: 20 25 30 40 50
    deleteLast();        // List: 20 25 30 40

    displayList();

    return 0;
}
