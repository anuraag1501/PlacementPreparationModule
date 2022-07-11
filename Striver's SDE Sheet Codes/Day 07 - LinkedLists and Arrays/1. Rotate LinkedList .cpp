#include <bits/stdc++.h> 
Node* rotate(Node *head, int k) {
    int n = 0;
    Node *tmp=head, *f;
    
    while(tmp) n++, tmp = tmp->next;
    k%=n;
    if(k==0) return head;
    
    tmp = head;
    
    int t = n-k;
    while(--t > 0) tmp = tmp->next;
    
    f = tmp->next;
    tmp->next = 0;
    
    tmp = f;
    while(tmp->next) tmp = tmp->next;
    tmp->next = head;
    
    return f;
}