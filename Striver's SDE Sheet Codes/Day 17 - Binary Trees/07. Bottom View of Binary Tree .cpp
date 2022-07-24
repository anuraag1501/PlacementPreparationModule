#include<map>
vector<int> bottomView(BinaryTreeNode<int> * root) {
    map<int,int> mp;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    if(root)
        q.push({root,0});
    
    while(!q.empty()){
        BinaryTreeNode<int>* node = q.front().first;
        int dis = q.front().second;
        q.pop();
        
        mp[dis] = node->data;
        
        if(node->left)
            q.push({node->left,dis-1});
        if(node->right)
            q.push({node->right,dis+1});
    }
    vector<int> ans;
    for(auto it : mp)
        ans.push_back(it.second);
    return ans;
}
