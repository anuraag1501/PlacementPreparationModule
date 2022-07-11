#include <bits/stdc++.h> 
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second){
    if(first == NULL) return second;
    if(second == NULL) return first;
    
    Node<int>* root,*tmp;
    if(first->data < second->data) root = first,first = first->next;
    else root = second, second = second->next;
    tmp = root;
    
    while(first && second){
        if(first->data < second->data){
            tmp->next = first;
            first = first->next;
            tmp = tmp->next;
        }else{
            tmp->next = second;
            second = second->next;
            tmp = tmp->next;
        }
    }
    if(first) tmp->next = first;
    if(second) tmp->next = second;
    return root;
}
