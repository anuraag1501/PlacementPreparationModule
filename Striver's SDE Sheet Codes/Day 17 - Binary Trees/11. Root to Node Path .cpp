bool dfs(TreeNode<int>* root, int x,vector<int>& path){
    if(!root) return false;
    
    path.push_back(root->data);
    if(root->data == x)
        return true;
    
    if(dfs(root->left,x,path))
        return true;
    if(dfs(root->right,x,path))
        return true;
    
    path.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x) {
    vector<int> path;
    dfs(root,x,path);
    return path;
}
