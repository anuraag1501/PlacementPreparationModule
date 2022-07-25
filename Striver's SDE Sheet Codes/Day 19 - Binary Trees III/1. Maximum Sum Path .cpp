long long dfs(TreeNode<int>* root,long long &ans){
    if(!root) return 0;
    
    if(!root->left && !root->right)
        return root->val;
    
    if(!root->left) return dfs(root->right,ans) + root->val;
    if(!root->right) return dfs(root->left,ans) + root->val;
    
    long long a = dfs(root->left,ans);
    long long b = dfs(root->right,ans);
    
    ans = max(ans,a+b+root->val);
    return max(a, b) + root->val;
}
long long int findMaxSumPath(TreeNode<int> *root) {
   long long ans = -1;
    dfs(root,ans);
    return ans;
}