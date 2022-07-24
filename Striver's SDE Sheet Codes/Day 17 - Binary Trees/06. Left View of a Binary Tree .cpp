vector<int> getLeftView(TreeNode<int> *root) {
    vector<int> ans;
    queue<pair<TreeNode<int>*,int>> q;
    if(root)
        q.push({root,0});
    
    while(!q.empty()){
        TreeNode<int>* node = q.front().first;
        int h = q.front().second;
        q.pop();
        
        if(ans.size()==h)
            ans.push_back(node->data);
        
        if(node->left)
            q.push({node->left,h+1});
        if(node->right)
            q.push({node->right,h+1});
    }
    return ans;
}