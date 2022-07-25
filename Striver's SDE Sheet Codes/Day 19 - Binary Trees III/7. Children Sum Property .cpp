int changeTree(BinaryTreeNode < int > * root,int mx = 0) {
    if(!root) return 0;
    
    mx = max(mx,root->data);
    
    if(!root->left && !root->right)
        return root->data = mx;
    
    if(!root->right)
        return root->data = changeTree(root->left,mx);
    
    if(!root->left)
        return root->data = changeTree(root->right,mx);
    
    int l = changeTree(root->left,mx/2);
    int r = changeTree(root->right,mx - mx/2);
    
    return root->data = l+r;
}  