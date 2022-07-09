#include <bits/stdc++.h>
Node *firstNode(Node *head){
    if(!head || !head->next) return NULL;
    
    Node *slow = head, *fast = head;
    
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast && fast->next && slow != fast);
    
    if(!fast || !fast->next) return NULL;
    fast = head;
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}