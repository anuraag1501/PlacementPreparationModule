#include <bits/stdc++.h>
int findIntersection(Node *firstHead, Node *secondHead){
    int n1=0,n2=0;
    
    Node *t1 = firstHead, *t2 = secondHead;
    while(t1) n1++, t1 = t1->next;
    while(t2) n2++, t2 = t2->next;
    
    t1 = firstHead, t2 = secondHead;
    while(n1 > n2 && t1) n1--, t1 = t1->next;
    while(n2 > n1 && t2) n2--, t2 = t2->next;
    
    while(t1 && t2 && t1 != t2) t1 = t1->next, t2 = t2->next;
    
    return t1 ? t1->data : -1;
}