// merge.cpp

#include "volsort.h"
#include <iostream>
using namespace std;

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
    l.head->next = msort(l.head->next, numeric);
}

Node *msort(Node *head, bool numeric) {
    
    // base case: return if head is null or only one element is left
    if (!head || !head->next) {
        return head;
    }

    // split list in half
    Node* left = nullptr;
    Node* right = nullptr;
    split(head, left, right);

    // recursively split both halves
    left = msort(left, numeric);
    right = msort(right, numeric);

    // merge the sorted halves
    return merge(left, right, numeric);

}

void split(Node *head, Node *&left, Node *&right) { // uses fast-slow pointer method
    
    // if there is none or only one element in list
    if (!head || !head->next) {
        left = head;
        right = nullptr;
        return;
    }

    // create slow and faster pointers
    Node* slow = head;
    Node* fast = head->next;

    // fast pointer moves twice as fast allowing the slow to end in the middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // split list
    left = head;
    right = slow->next;
    slow->next = nullptr;

}

Node *merge(Node *left, Node *right, bool numeric) {

    // we will add on to tail while head keeps track of beginning
    Node head;
    Node* tail = &head; 

    // loop until left or right list reaches null
    while (left && right) {

        // merge list based on if it is numeric or not
        if (numeric) {
            if (node_number_compare(left, right)) {
                // if left is less than right then add to list and increment
                tail->next = left;
                left = left->next;

            } else { // else do the same to right
                tail->next = right;
                right = right->next;
            }
    
        } else { // same thing but for string comparison
            if (node_string_compare(left, right)) {
                tail->next = left;
                left = left->next;

            } else {
                tail->next = right;
                right = right->next;
            }

        } 
        //move tail to newly added node
        tail = tail->next;
    }

    // add any remaining elements
    if (left) {
        tail->next = left;
    } else if (right) {
        tail->next = right;
    }

    // return beginning of merged list
    return head.next;

}

