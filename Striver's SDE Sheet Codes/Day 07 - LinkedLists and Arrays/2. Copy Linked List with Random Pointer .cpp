#include <bits/stdc++.h> 
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head){
    if(head==NULL) return head;
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> mp;
    
    LinkedListNode<int> *root = new LinkedListNode<int>(head->data),*t1 = head, *t2 = root;
    
    mp[head] = root;
   
    while(t1->next){
        t1 = t1->next;
        t2->next = new LinkedListNode<int>(t1->data);
        t2 = t2->next;
        mp[t1] = t2;
    }
    t1 = head;
    t2 = root;
    while(t1){
        t2->random = mp[t1->random];
        t1 = t1->next;
        t2 = t2->next;
    }
    return root;
}
