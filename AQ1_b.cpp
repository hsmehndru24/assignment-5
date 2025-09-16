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
void insert_after_position(struct Node *p,int position,int x){
    Node *t = new Node;
    // Node *p = new Node;
    t->data = x;
    //p=first;
    for(int i=0;i<position-1;i++){
        p = p->next;
    }
    t->next=p->next;
    p->next=t;
}

int main(){
    int A[]={8,3,9,7,6};
    create(A,5);
    cout << "original ll: ";
    display(first);
    insert_after_position(first,5,10);
    cout << endl << "ll after insertion at end: ";
    display(first);
    return 0;
}