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

void List::push_front(const std::string &s){
  Node *current = head;
  Node *next = head->next;
  Node *newNode = new Node(s);
  *current->next = *newNode;
  *newNode->next = *next;
}

bool node_number_compare(const Node *a, const Node *b){

}

bool node_string_compare(const Node *a, const Node *b){

}