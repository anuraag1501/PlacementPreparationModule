#include <bits/stdc++.h>
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(head == NULL || head->next == NULL) return head;
    Node *root = NULL, *last;
    for(int i=0; i<n && head; i++){
        if(b[i]<=0) continue;
        Node *f = head, *l = f;
        head = head->next;
        f->next = NULL;
        while(head && --b[i] > 0){
            Node *t = head;
            head = head->next;
            t->next = f;
            f = t;
        }
        if(!root) root = f, last = l;
        else last->next = f, last = l;
    }
    if(!root) return head;
    if(last) last->next = head;
    return root;
}