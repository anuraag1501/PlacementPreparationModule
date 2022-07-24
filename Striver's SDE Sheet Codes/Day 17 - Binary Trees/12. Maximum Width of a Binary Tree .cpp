#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root) {
    if(!root) return 0;
    vector<int> v;
    
    queue<tuple<TreeNode<int>*,int> > q;
    if(root)
        q.push(make_tuple(root,0));
    
    while(!q.empty()){
        auto node = get<0>(q.front());
        int lev = get<1>(q.front());
        q.pop();
        
        if(v.size() == lev)
            v.push_back(0);
        
        v[lev]++;
        
        if(node->left)
            q.push(make_tuple(node->left,lev+1));
        if(node->right)
            q.push(make_tuple(node->right,lev+1));
    }
    return *max_element(v.begin(),v.end());
}