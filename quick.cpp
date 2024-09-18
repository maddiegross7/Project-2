// quick.cpp - a custom implementation of the quicksort algorithm designed to work on single linked lists
// with help from TA Zach

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

//wrapper for quicksort recursion
void quick_sort(List &l, bool numeric) {
    l.head->next = qsort(l.head->next, numeric);
}

//quicksort: recursively divides list into sublists higher or lower than pivot, concatenates them back together, and returns the head of the resulting list
Node *qsort(Node * head, bool numeric) {
    if(head == NULL || head->next == NULL){
        return head;
    }else{
        Node * pivot = head;
        Node * leftList = NULL;//becomes head pointer of left list in partition
        Node * rightList = NULL;//becomes head pointer of right list in partition
        partition(head, pivot, leftList, rightList, numeric);
        //recursive calls
        leftList = qsort(leftList, numeric);
        rightList = qsort(rightList, numeric);
        //concat left, pivot, & right
        pivot->next = rightList;
        return concatenate(leftList, pivot); 
    }
}

//partition: creates two sublists of nodes greater or less than the given pivot
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    Node * tempL = NULL;
    Node * tempR = NULL;
    for(Node * p = pivot->next; p != NULL; p = p->next){
        if(!(comp(pivot, p, numeric))){
            if(left == NULL){//left side: less than pivot
                left = p;
                tempL = left;
            }else{
                tempL->next = p;
                tempL = tempL->next;
            }
        }else{
            if(right == NULL){//right side: greater than pivot
                right = p;
                tempR = right;
            }else{
                tempR->next = p;
                tempR = tempR->next;
            }
        }
    }
    if(tempR != NULL){
        tempR->next = NULL;
    }
    if(tempL != NULL){
        tempL->next = NULL;
    }
}

//concatenate: combine given sublists, return node pointer to the leftmost
Node *concatenate(Node *left, Node *right) {
    Node * p = left;
    if(left == NULL){
        return right;
    }
    while(p->next != NULL){
        p = p->next;
    }
    p->next = right;
    return left;
}

