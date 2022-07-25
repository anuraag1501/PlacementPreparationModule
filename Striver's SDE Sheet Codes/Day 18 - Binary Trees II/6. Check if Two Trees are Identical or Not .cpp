bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    
    if(!identicalTrees(root1->left , root2->left)) return false;
    if(!identicalTrees(root1->right,root2->right)) return false;
    
    return root1->data == root2->data;
}