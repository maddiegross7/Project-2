#include "volsort.h"
#include <iostream>
#include <string>
//audrey was here

using namespace std;

List::List() {
    head = new Node();
    head->next = NULL;
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
    Node *newNode = new Node();
    newNode->number = stoi(s);
    newNode->string = s;
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

bool node_number_compare(const Node *a, const Node *b){
    return a->number < b->number;//swap if returns false
}

bool node_string_compare(const Node *a, const Node *b){
    return (a->string.compare(b->string) <= 0) ;//swap if returns false
}