// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void stl_sort(List &l, bool numeric) {
   vector<struct Node *> list;

   Node *current = l.head->next;

    while(current!=NULL){
        list.push_back(current);
        current = current->next;
    }

    if(numeric){
        sort(list.begin(), list.end(), node_number_compare);
    }else{
        sort(list.begin(), list.end(), node_string_compare);
    }

    //cout << "size:" << list.size() << endl;
    l.head->next = *list.begin();
    for(auto it = list.begin(); it != list.end(); it++){
        Node* now = *it;
        now->next = *(it+1);
        // cout << "number: " << now->number << " string: " << now->string << endl;
        // cout << now->next->number << endl;
    }

}

