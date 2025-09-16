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

void deleteFromBeginning() {
    if (first == NULL) {
        cout << "List is empty, cannot delete" << endl;
        return;
    }
    Node *temp = first;
    first = first->next;
    delete temp;
}

void deleteFromEnd() {
    if (first == NULL) {
        cout << "List is empty, cannot delete" << endl;
        return;
    }
    if (first->next == NULL) {
        delete first;
        first = NULL;
        return;
    }
    Node *p = first;
    while (p->next->next != NULL) {
        p = p->next;
    }
    Node *temp = p->next;
    p->next = NULL;
    delete temp;
}

void deleteByValue(int value) {
    if (first == NULL) {
        cout << "List is empty, cannot delete" << endl;
        return;
    }
    if (first->data == value) {
        Node *temp = first;
        first = first->next;
        delete temp;
        return;
    }
    Node *p = first;
    while (p->next != NULL && p->next->data != value) {
        p = p->next;
    }
    if (p->next == NULL) {
        cout << "Node with value " << value << " not found" << endl;
        return;
    }
    Node *temp = p->next;
    p->next = temp->next;
    delete temp;
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
    int A[] = {2, 3, 60, 4, 6, 5, 7, 8};
    create(A, 8);
    cout << "Original list: ";
    display(first);
    
    cout << endl << "After deleting from beginning: ";
    deleteFromBeginning();
    display(first);
    
    cout << endl << "After deleting from end: ";
    deleteFromEnd();
    display(first);
    
    cout << endl << "After deleting node with value 60: ";
    deleteByValue(60);
    display(first);
    
    deleteList(); // Clean up memory
    return 0;
}