// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, /*Node *left, Node *right,*/ bool numeric);
//void qsort(List &l, int left, int right, bool numeric);
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    qsort(l.head, /*l.head->next, l.at(l.nodeCount() - 1),*/ numeric);
}

Node *qsort(Node * head, bool numeric) {
    if(!(comp(head->next, head->next->next, numeric))){
        return head;//good chance this is backwards - think i fixed it
    }else{
        Node * pivot = head->next;
        Node * leftList;//becomes head pointer of left list in partition
        Node * rightList;//becomes head pointer of right list in partition
        partition(head, pivot, leftList, rightList, numeric);
        qsort(leftList, numeric);
        qsort(rightList, numeric);
        return concatenate(leftList, rightList); 
    }
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    List leftL;
    List rightL;
    left = leftL.head;
    right = rightL.head;
    rightL.push_front(pivot->string);//probably also in wrong order
    for(Node * p = pivot->next; p != NULL; p = p->next){
        if(comp(pivot, p, numeric)){//possibly backwards
            rightL.push_front(p->string);
        }else{
            leftL.push_front(p->string);
        }
    }
}

Node *concatenate(Node *left, Node *right) {
    Node * p = left;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = right;
    return left;
}

