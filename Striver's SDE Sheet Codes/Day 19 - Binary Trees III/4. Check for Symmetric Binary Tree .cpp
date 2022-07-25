bool check(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right){
    if(!left && !right) return true;
    if(!left || !right) return false;
    
    if(!check(left->right,right->left)) return false;
    if(!check(left->left,right->right)) return false;
    
    return left->data == right->data;
}
bool isSymmetric(BinaryTreeNode<int>* root) {
    if(!root) return true;
    return check(root->left,root->right);
}