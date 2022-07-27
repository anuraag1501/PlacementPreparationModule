void makeList(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &head, BinaryTreeNode<int>* &prev){
    if(!root) return;
    
    makeList(root->left,head,prev);
    
    if(!head) head = root;
    if(prev) prev->right = root;
    root->left = prev;
    prev = root;
    
    makeList(root->right,head,prev);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>*head = NULL,*prev = NULL;
    makeList(root,head,prev);
    return head;
}