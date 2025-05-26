#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

// Function to insert node at the end
void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to display the list normally
void displayList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// (a) Function to display elements in reverse order
void displayReverseOrder() {
    Node* temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// (b) Function to find and delete the middle element
void findAndDeleteMiddle() {
    if (head == NULL) return;

    Node* mid = head;
    Node* runner = head;

    while (runner != NULL && runner->next != NULL) {
        mid = mid->next;
        runner = runner->next->next;
    }

    if (mid->prev != NULL)
        mid->prev->next = mid->next;
    if (mid->next != NULL)
        mid->next->prev = mid->prev;
    if (mid == head)
        head = mid->next;
    if (mid == tail)
        tail = mid->prev;

    free(mid);
}

// (c) Function to swap first and last elements
void swapFirstAndLast() {
    if (head == NULL || head == tail) return;

    int temp = head->data;
    head->data = tail->data;
    tail->data = temp;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printf("Original List:\n");
    displayList();

    printf("List in Reverse Order:\n");
    displayReverseOrder();

    findAndDeleteMiddle();
    printf("After Deleting Middle Element:\n");
    displayList();

    swapFirstAndLast();
    printf("After Swapping First and Last Elements:\n");
    displayList();

    return 0;
}
