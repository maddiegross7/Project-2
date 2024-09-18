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
    if(head == NULL){
        std::cout << "reached base case\n";
        return head;
    }else{
        std::cout << "doing recursive call\n Incoming list: ";
        dump_node(head);
        Node * pivot = head;
        std::cout << "Pivot: " << pivot->number << "\n";
        Node * leftList = NULL;//becomes head pointer of left list in partition
        Node * rightList = NULL;//becomes head pointer of right list in partition
        partition(head, pivot, leftList, rightList, numeric);
        std::cout << "Left: ";
        dump_node(leftList);
        std::cout << "Right: ";
        dump_node(rightList);
        leftList = qsort(leftList, numeric);
        rightList = qsort(rightList, numeric);
        pivot->next = rightList;
        return concatenate(leftList, pivot); 
    }
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    Node * temp;
    for(Node * p = pivot->next; p != NULL; p = p->next){
        //start at first node go til end
        if(!(comp(pivot, p, numeric))){
            if(right == NULL){
                right = p->next;
                temp = p;
            }else{
                temp->next = p;
                temp = temp->next;
            }
            std::cout << "pushing " << p->number << " to right list\n";
        }else{
            if(left == NULL){
                left = p->next;
                temp = p;
            }else{
                temp->next = p;
                temp = temp->next;
            }
            std::cout << "pushing " << p->number << " to left list\n";
        }
    }
}

// void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
//     Node * tempL;
//     Node * tempR;
//     for(Node * p = pivot->next; p != NULL; p = p->next){
//         if(!(comp(pivot, p, numeric))){
//             if(right == NULL){
//                 right = p->next;
//                 tempR = right;
//             }else{
//                 tempR->next = p;
//                 tempR = p;
//             }
//             std::cout << "pushing " << p->number << " to right list\n";
//         }else{
//             if(left == NULL){
//                 left = p->next;
//                 tempL = left;
//             }else{
//                 tempL->next = p;
//                 tempL = p;
//             }
//             std::cout << "pushing " << p->number << " to left list\n";
//         }
//     }
//     pivot->next = NULL;
//     tempR->next = NULL;
//     tempL->next = NULL;
// }

Node *concatenate(Node *left, Node *right) {
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

