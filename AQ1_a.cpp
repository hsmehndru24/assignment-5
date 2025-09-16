#include<iostream>
using namespace std;

struct Node{
    int data ;
    struct Node *next ;
}*first=NULL;
void create(int A[],int n){
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t = new Node ;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct Node *p){
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
void insert(int x){
    Node *t = new Node;
    t->data=x;
    t->next=first;
    first=t;
}
int main(){
    int A[]={2,3,1,4,6,5,7,8};
    create(A,8);
    cout << "original ll: ";
    display(first);
    insert(0);
    cout << endl << "ll after insertion before first node: ";
    display(first);

    return 0;
}