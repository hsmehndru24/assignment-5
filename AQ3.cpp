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
        cout << p->data << " ";
        p = p->next;
    }
}

int findMiddle() {
    if (first == NULL) {
        cout << "List is empty" << endl;
        return -1; // Indicate empty list
    }
    if (first->next == NULL) {
        return first->data; // Single node
    }
    Node *slow = first;
    Node *fast = first;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
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
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    cout << "Linked list: ";
    display(first);
    int middle = findMiddle();
    cout << endl << "Middle element: " << middle;
    deleteList(); // Clean up memory
    return 0;
}