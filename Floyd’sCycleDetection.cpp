// Problem: Detect Cycle in a Linked List..
// Use Floyd’s Tortoise and Hare algorithm to check if a loop exists in a linked list.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head; // Creating cycle
    cout << "Cycle detected? " << (hasCycle(head) ? "Yes" : "No");
    return 0;
}
