#include <stdio.h>
#include <stdlib.h>

// Structure of a Node in Doubly Linked List
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Global head and tail pointers
Node* head = NULL;
Node* tail = NULL;

// Function to insert a node at the end of the list
void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // allocate memory for new node
    newNode->data = value; // set data
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) { // if list is empty
        head = tail = newNode;
    } else { // add to end
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to display the list from head to tail
void displayList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); // print data
        temp = temp->next; // move forward
    }
    printf("\n");
}

// (a) Function to display elements in reverse order (from tail to head)
void displayReverseOrder() {
    Node* temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data); // print data
        temp = temp->prev; // move backward
    }
    printf("\n");
}

// (b) Function to find and delete the middle node
void findAndDeleteMiddle() {
    if (head == NULL) return; // empty list check

    Node* mid = head;
    Node* runner = head;

    // Use two pointers: 'runner' moves twice as fast as 'mid'
    while (runner != NULL && runner->next != NULL) {
        mid = mid->next;
        runner = runner->next->next;
    }

    // Adjust pointers to delete the middle node
    if (mid->prev != NULL)
        mid->prev->next = mid->next;
    if (mid->next != NULL)
        mid->next->prev = mid->prev;

    // Update head/tail if necessary
    if (mid == head)
        head = mid->next;
    if (mid == tail)
        tail = mid->prev;

    free(mid); // free memory
}

// (c) Function to swap the data of first and last nodes
void swapFirstAndLast() {
    if (head == NULL || head == tail) return; // nothing to swap if list has 0 or 1 node

    int temp = head->data;
    head->data = tail->data;
    tail->data = temp;
}

// Main function to test the above implementations
int main() {
    // Insert elements
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printf("Original List:\n");
    displayList();

    // (a) Display list in reverse
    printf("List in Reverse Order:\n");
    displayReverseOrder();

    // (b) Delete the middle element
    findAndDeleteMiddle();
    printf("After Deleting Middle Element:\n");
    displayList();

    // (c) Swap first and last elements
    swapFirstAndLast();
    printf("After Swapping First and Last Elements:\n");
    displayList();

    return 0;
}
