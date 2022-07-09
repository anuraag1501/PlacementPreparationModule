//Excellent Question....
#include <bits/stdc++.h> 

Node* merge(Node* a, Node *b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    
    Node *root;
    if(a->data < b->data) root = a, a = a->child;
    else root = b, b= b->child;
    Node *last = root;
    
    while(a && b){
        if(a->data < b->data) last->child = a, a = a->child;
        else last->child = b, b = b->child;
        last = last->child;
    }
    if(a) last->child = a;
    if(b) last->child = b;
    return root;
}

Node *MergeSort(Node *h){
    if(h && h->next){
        Node *fast = h->next->next, *slow = h;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        MergeSort(h);
        MergeSort(fast);
        return merge(h,fast);
    }
    return h;
}

Node* flattenLinkedList(Node* h){
    if(!h || !h->next) return h;
    return MergeSort(h);
}
