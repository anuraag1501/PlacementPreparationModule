TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q) {
	if(!root) return root;
    
    if(root->data > P->data && root->data > Q->data){
        auto n = LCAinaBST(root->left,P,Q);
        if(n==NULL)
            return root;
        return n;
    } 
    
    if(root->data < P->data && root->data < Q->data){
        auto n = LCAinaBST(root->right,P,Q);
        if(n==NULL)
            return root;
        return n;
    } 
    return root;
}
