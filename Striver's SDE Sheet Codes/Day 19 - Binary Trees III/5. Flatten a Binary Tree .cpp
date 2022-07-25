TreeNode<int> *flattenBinaryTree(TreeNode<int> *root) {
    if(!root) return root;
    
    if(!root->left) {
        flattenBinaryTree(root->right);
        return root;
    }
    
    flattenBinaryTree(root->left);
    TreeNode<int>* pre = root->left;
    while(pre->right) pre = pre->right;
    
    pre->right = root->right;
    root->right = root->left;
    root->left = NULL;
    flattenBinaryTree(pre->right);
    return root;
}