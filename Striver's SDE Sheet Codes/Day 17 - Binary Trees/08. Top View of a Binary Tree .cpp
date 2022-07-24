#include<map>
vector<int> getTopView(TreeNode<int> *root) {
    map<int,int> mp;
    queue<pair<TreeNode<int>*,int>> q;
    if(root)
        q.push({root,0});
    
    while(!q.empty()){
        TreeNode<int>* node = q.front().first;
        int dis = q.front().second;
        q.pop();
        
        if(mp.find(dis) == mp.end())
            mp[dis] = node->val;
        
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