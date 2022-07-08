#include <bits/stdc++.h> 
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL) return head;
    LinkedListNode<int> *f = head,*s;
    
    //f denotes the root node of List Reversed so Far.....
    // and head is the remaining list to be reversed
    head = head->next;
    f->next = NULL;
    
    while(head){
        s = head;
        head = head->next;
        s->next = f;
        f = s;
    }
    return f;
}