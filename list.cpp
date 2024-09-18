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

void List::push_front(const std::string &s){
    Node *current = head;
    Node *newNode = new Node();
    newNode->number = stoi(s);
    newNode->string = s;
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

int List::nodeCount(){
    //loop thru list, return count
    int i = 0;
    for(Node * p = head; p != NULL; p = p->next){
        i++;
    }
    return i;
}

Node * List::at(const int &index){
    //return pointer to node at given index
    if(index >= nodeCount()){
        throw index;
    }

    Node * p = head;
    for(int i = 0; i < index; i++){
        p = p->next;
    }
    return p;
}

void dump_node(Node * n){
    std::cout << "Node dump: ";
    if(n == NULL){
        std::cout << "n is NULL" << endl;
        return;
    }
    while(n != NULL){
        std::cout << n->number << " ";
        n = n->next;
    }
}

int comp(const Node *a, const Node *b, bool numeric){
    //cout << "running comp\n";
    if(numeric){
        return node_number_compare(a, b);
    }else{
        return node_string_compare(a, b);
    }
}

bool node_number_compare(const Node *a, const Node *b){
    //cout << "running node_number_compare\n";
    return a->number < b->number;//swap if returns false
}

bool node_string_compare(const Node *a, const Node *b){
    return (a->string.compare(b->string) <= 0);//swap if returns false
}