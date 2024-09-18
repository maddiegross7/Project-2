// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <vector>

using namespace std;

void stl_sort(List &l, bool numeric) {
    //put nodes into vector
    vector<struct Node *> list;
    Node *current = l.head->next;
    while(current!=NULL){
        list.push_back(current);
        current = current->next;
    }

    //decide comparison to use
    if(numeric){
        sort(list.begin(), list.end(), node_number_compare);
    }else{
        sort(list.begin(), list.end(), node_string_compare);
    }

    //set head->next to the start of the list to start the new order of the list
    if(!list.empty()){
        l.head->next = *list.begin();
        for(auto it = list.begin(); it != list.end(); it++){
            Node* now = *it;
            if(it != list.end()){
                now->next = *(it+1);
            }else{
                now->next = NULL;
            }
            
        }
    }else{
        l.head->next = NULL;
    }
    

}

