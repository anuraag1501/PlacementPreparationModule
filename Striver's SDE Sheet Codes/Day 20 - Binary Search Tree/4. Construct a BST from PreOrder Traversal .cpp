TreeNode<int>* tree(vector<int>&pre,int& i,int j, int n){
    if(i>=n) return NULL;
    
    TreeNode<int>*root = new TreeNode<int>(pre[i++]);
    
    if(i==n) return root;
    
    if(pre[i] < root->data)
        root->left = tree(pre,i,i,n);
    
    if(i==n) return root;
    
    if(j && pre[i] > pre[j-1]) return root;
    
    root->right = tree(pre,i,j,n);
    
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder) {
    int i=0;
    return tree(preOrder, i,0,preOrder.size());
}