TreeNode<int>* tree(vector<int>&post, vector<int>& in, int ii, int ij, int& pi){
    if(ii > ij) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(post[pi]);
    
    int m = ij;
    while(in[m] != post[pi]) m--;
    
    pi--;
    root->right = tree(post,in,m+1,ij,pi);
    
    root->left = tree(post,in,ii,m-1,pi);
    
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) {
    int n = postOrder.size(), pi = n-1;
    
    return tree(postOrder,inOrder,0,n-1,pi);
}
