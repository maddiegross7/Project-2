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
    if(head->next == NULL){
        std::cout << "base case comparison\n";
        return head;//good chance this is backwards - think i fixed it
    }else{
        std::cout << "doing recursive call\n";
        Node * pivot = head;
        Node * leftList;//becomes head pointer of left list in partition
        Node * rightList;//becomes head pointer of right list in partition
        partition(head, pivot, leftList, rightList, numeric);
        qsort(leftList, numeric);
        qsort(rightList, numeric);
        return concatenate(leftList, rightList); 
    }
}

// void qsort(List &l, int left, int right, bool numeric){//in place attempt
//     if(right - left > 1){
//         int partitionPoint = partition(l, right, left, numeric);

//     }
// }

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    std::cout << "running partition\n";
    List leftL;
    List rightL;
    left = leftL.head;
    right = rightL.head;
    rightL.push_front(pivot->string);//probably also in wrong order
    for(Node * p = pivot->next; p != NULL; p = p->next){
        if(comp(pivot, p, numeric) >= 0){//possibly backwards
            std::cout << "pushing to left list\n";
            rightL.push_front(p->string);
        }else{
            std::cout << "pushing to right list\n";
            leftL.push_front(p->string);
        }
    }
}

Node *concatenate(Node *left, Node *right) {
    std::cout << "running concatenate\n";
    Node * p = left;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = right;
    return left;
}

