// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    qsort(l.head->next, numeric);
}

Node *qsort(Node * head, bool numeric) {
    std::cout << "hey guys we're quicksorting\n";
    dump_node(head);
    if(head == NULL){
        std::cout << "base case comparison\n";
        return head;
    }else{
        std::cout << "doing recursive call\n";
        Node * pivot = head;
        Node * leftList = NULL;//becomes head pointer of left list in partition
        Node * rightList = NULL;//becomes head pointer of right list in partition
        partition(head, pivot, leftList, rightList, numeric);
        leftList = qsort(leftList, numeric);
        rightList = qsort(rightList, numeric);
        pivot->next = rightList;
        return concatenate(leftList, pivot); 
    }
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    std::cout << "running partition\n";
    for(Node * p = pivot->next; p != NULL; p = p->next){
        //start at first node go til end
        Node * temp;
        if(comp(pivot, p, numeric) >= 0){//possibly backwards
            if(p == pivot->next){
                right = p;
                temp = p;
            }else{
                temp->next = p;
                temp = temp->next;
            }
            std::cout << "pushing to right list\n";
        }else{
            if(p == pivot->next){
                left = p;
                temp = p;
            }else{
                temp->next = p;
                temp = temp->next;
            }
            std::cout << "pushing to left list\n";
        }
    }
}

Node *concatenate(Node *left, Node *right) {
    std::cout << "running concatenate\n";
    Node * p = left;
    if(left == NULL){//segfault check
        return right;
    }
    while(p->next != NULL){
        p = p->next;
    }
    p->next = right;
    return left;
}

