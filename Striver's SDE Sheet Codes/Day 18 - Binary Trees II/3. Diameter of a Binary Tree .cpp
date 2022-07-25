int get(TreeNode<int>*root, int&d){
    if(!root) return 0;
    
    int l = get(root->left,d);
    int r = get(root->right,d);
    
    d = max(d,l+r);
    return 1 + max(l,r);
}
int diameterOfBinaryTree(TreeNode<int> *root) {
    if(!root) return 0;
    int d = 0;
    get(root,d);
    return d;
}
