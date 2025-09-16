#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n) {
    struct Node *t, *last;
    first = new Node;
    if (!first) {
        cout << "Memory allocation failed" << endl;
        return;
    }
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node;
        if (!t) {
            cout << "Memory allocation failed" << endl;
            return;
        }
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    if (p == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    while (p != NULL) {
        cout << p->data;
        if (p->next != NULL) {
            cout << "->";
        }
        p = p->next;
    }
    cout << "->NULL";
}

void reverse() {
    if (first == NULL || first->next == NULL) {
        return; // Empty or single-node list, no reversal needed
    }
    Node *prev = NULL;
    Node *current = first;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move current to next
    }
    first = prev; // Update head to last node
}

void deleteList() {
    Node *p = first;
    while (p != NULL) {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
    first = NULL;
}

int main() {
    int A[] = {1, 2, 3, 4};
    create(A, 4);
    cout << "Original list: ";
    display(first);
    reverse();
    cout << endl << "Reversed list: ";
    display(first);
    deleteList(); // Clean up memory
    return 0;
}