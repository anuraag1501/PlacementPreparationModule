#include<bits/stdc++.h>
struct Node{
    unordered_map<char,Node*> mp;
    int count = 0;
    bool fin=0;
};
Node *root;
void insert(string &s){
    Node *node = root;
    for(auto ch : s){
        if(node->mp.find(ch) == node->mp.end())
            node->mp[ch] = new Node;
        node = node->mp[ch];
        node->count++;
    }
    node->fin = 1;
}
bool valid(string& s, Node* root,int i, int n){
    if(i==n) return true;
    
    root = root->mp[s[i]];
    if(root->fin==false) return false;
    if(root->count < n-i) return false;
    return valid(s,root,i+1,n);
}
string completeString(int n, vector<string> &a){
    root = new Node;
    for(auto &s : a) insert(s);
     
    string ans = "";
    for(auto &s : a)
        if(valid(s,root,0,s.length()) &&
          ((s.length()==ans.length() && s<ans) || s.length() > ans.length()))
            ans = s;
        
    if(ans.length()==0) return "None";
    return ans;
}