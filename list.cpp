#include "volsort.h"
//audrey was here
//ava waz h3re
// mary was here?

List::List() {
    head = NULL;
}

List::~List() {
    if(!(head == NULL)){
        Node * p = head;
        while(p != NULL){
            Node * next = p->next;
            delete p;
            p = next;
        }
    }
}

bool node_number_compare(const Node *a, const Node *b){

}

bool node_string_compare(const Node *a, const Node *b){

}
