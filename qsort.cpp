// qsort.cpp
// sites used: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm, https://www.programiz.com/c-programming/library-function/string.h/strcmp, 

#include "volsort.h"
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <array>
#include <iostream>
using namespace std;

// Updated Comparator Functions to make qsort take int compare rather than bool compare
int number_compare(const void *a, const void *b) {
   Node* node_a = *(Node**)a; 
   Node* node_b = *(Node**)b; 
   return (node_a->number > node_b->number) - (node_a->number < node_b->number); 
}

int string_compare(const void *a, const void *b){
   Node* node_a=*(Node**)a;
   Node* node_b=*(Node**)b;
   return strcmp(node_a -> string.c_str(),node_b -> string.c_str());
}

//same as STL
void qsort_sort(List &l, bool numeric) {

    vector<struct Node *> list;

   Node *current = l.head->next;

    while(current!=NULL){
        list.push_back(current);
        current = current->next;
    }

    if(numeric){
		//implementing qsort here using .data(), .size(), sizeof, and int compares
       qsort(list.data(), list.size(), sizeof(Node *), number_compare);
    }else{
		qsort(list.data(), list.size(), sizeof(Node *), string_compare);
    }

    l.head->next = *list.begin();
    for(auto it = list.begin(); it != list.end(); it++){
        Node* now = *it;
        now->next = *(it+1);
    }

}

