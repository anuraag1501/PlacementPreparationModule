#include<map>
vector<int> verticalOrderTraversal(TreeNode<int> *root) {
    map<int,vector<int>> mp;
    vector<int> verticalOrder;
    queue<pair<TreeNode<int>*,int>> q;
    
    if(root)
        q.push({root,0});
    while(!q.empty()){
        auto node = q.front().first;
        int dis = q.front().second;
        q.pop();
        
        mp[dis].push_back(node->data);
        if(node->left)
            q.push({node->left,dis-1});
        if(node->right)
            q.push({node->right,dis+1});
    }
    for(auto it : mp)
        verticalOrder.insert(verticalOrder.end(),
                             it.second.begin(),
                             it.second.end());
    return verticalOrder;
}