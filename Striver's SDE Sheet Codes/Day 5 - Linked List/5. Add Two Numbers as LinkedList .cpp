#include <bits/stdc++.h> 
Node *addTwoNumbers(Node *head1, Node *head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    int carry = (head1->data + head2->data)/10;
    Node *root = new Node((head1->data + head2->data)%10), *tmp=root;
    head1 = head1->next;
    head2 = head2->next;
    
    while(carry || head1 || head2){
        if(head1) carry += head1->data, head1 = head1->next;
        if(head2) carry += head2->data, head2 = head2->next;
        
        tmp->next = new Node(carry%10);
        tmp = tmp->next;
        carry /= 10;
    }
    return root;
}