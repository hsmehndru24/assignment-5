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

int countAndDeleteAllKey(int key) {
    int count = 0;
    Node *p = first;
    Node *prev = NULL;

    // Handle nodes at the beginning
    while (p != NULL && p->data == key) {
        count++;
        first = p->next;
        delete p;
        p = first;
    }

    // Handle remaining nodes
    while (p != NULL) {
        if (p->data == key) {
            count++;
            prev->next = p->next;
            delete p;
            p = prev->next;
        } else {
            prev = p;
            p = p->next;
        }
    }
    return count;
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
    int A[] = {1, 2, 1, 2, 1, 3, 1};
    int key = 1;
    create(A, 7);
    cout << "Original list: ";
    display(first);
    
    int count = countAndDeleteAllKey(key);
    cout << endl << "Count of " << key << ": " << count;
    
    cout << endl << "Updated list after deleting all " << key << ": ";
    display(first);
    
    deleteList(); // Clean up memory
    return 0;
}