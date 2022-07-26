bool validateBST(BinaryTreeNode<int> *root,int mn = -1e9, int mx = 1e9) {
    if(!root) return true;
    
    if(root->data > mx || root->data < mn) return false;
    
    if(!validateBST(root->left, mn, min(mx,root->data) ) ) return false;
    if(!validateBST(root->right, max(mn,root->data), mx) ) return false;
    
    return true;
}