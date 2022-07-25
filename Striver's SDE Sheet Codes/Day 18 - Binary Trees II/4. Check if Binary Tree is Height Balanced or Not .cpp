int check(BinaryTreeNode<int>*root){
    if(!root) return 0;
    
    int left = check(root->left);
    int right = check(root->right);
    
    if(left == -1 || right == -1 || abs(left-right) > 1) return -1;
    
    return 1 + max(left,right);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    return check(root) == -1 ? 0 : 1;
}