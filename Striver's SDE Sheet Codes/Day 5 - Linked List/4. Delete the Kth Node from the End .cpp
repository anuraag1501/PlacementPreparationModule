#include <bits/stdc++.h>
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K){
    if(K==0) return head;
    int n = 0, i=0;
    
    LinkedListNode<int> *tmp = head;
    while(tmp) n++,tmp=tmp->next;
    n -= K;
    
    if(n==0){
        head = head->next;
        return head;
    }
    
    tmp = head;
    while(--n > 0) tmp = tmp->next;
    
    if(tmp->next) tmp->next = tmp->next->next;
    
    return head;;
}