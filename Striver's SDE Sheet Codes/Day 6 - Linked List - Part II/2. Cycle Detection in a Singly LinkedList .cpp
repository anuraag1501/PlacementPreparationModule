#include <bits/stdc++.h>
bool detectCycle(Node *head){
    if(head == NULL || head->next == NULL) return 0;
    
    Node *slow = head, *fast = head;
    
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast && fast->next && slow != fast);
    
    return fast == slow;
}