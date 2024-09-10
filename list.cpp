#include "volsort.h"
//audrey was here

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

void List::push_front(const std::string &s, bool numeric){
  Node *current = head;
  Node *next = head->next;
  Node *newNode = new Node(s, numeric);
  *current->next = *newNode;
  *newNode->next = *next;
}

bool node_number_compare(const Node *a, const Node *b){
    return 1;
}

bool node_string_compare(const Node *a, const Node *b){
    return 1;
}