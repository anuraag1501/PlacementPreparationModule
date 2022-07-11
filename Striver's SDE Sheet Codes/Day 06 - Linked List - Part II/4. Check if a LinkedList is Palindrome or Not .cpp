#include <bits/stdc++.h>
bool isPalindrome(LinkedListNode<int> *head) {
    if(!head || !head->next) return true;
    LinkedListNode<int> *temp = head;
    stack<LinkedListNode<int>*> st;
    
    while(temp){
        st.push(temp);
        temp = temp->next;
    }
    
    while(!st.empty()){
       if(st.top()->data != head->data) return false;
        head = head->next;
        st.pop();
    }
    return true;
}	