bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(!root) return false;
    
    if(root->data == x) return true;
    
    if(searchInBST(root->left,x) || searchInBST(root->right,x))
        return true;
    
    return false;
}