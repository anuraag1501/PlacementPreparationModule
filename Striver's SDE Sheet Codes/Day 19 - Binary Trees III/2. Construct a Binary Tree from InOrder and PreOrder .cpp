#define vi vector<int>
TreeNode<int> *tree(vi& inorder,vi& preorder,int ii, int ij, int &pi){
    if(ii > ij)
        return NULL;
    
    TreeNode<int> *root = new TreeNode<int>(preorder[pi]);
    
    int m = ii;
    while(inorder[m] != preorder[pi]) m++;
    pi++;
    
    root->left = tree(inorder,preorder,ii,m-1,pi);
    
    root->right = tree(inorder,preorder,m+1,ij,pi);
    
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
    int n = inorder.size(),pi=0;
    return tree(inorder,preorder,0,n-1,pi);
}