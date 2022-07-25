bool convert(TreeNode<int>*curr,TreeNode<int>*par,int t,TreeNode<int>* &head){
    if(!curr) return 0;
    
    if(curr->data == t){
        head = curr;
        curr->left = par;
        return 1;
    }
    
    if(convert(curr->left,curr,t,head)){
        curr->left = par;
        return 1;
    } else if(convert(curr->right,curr,t,head)){
        curr->right = par;
        swap(curr->left, curr->right);
        return 1;
    }
    return 0;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf) {
    TreeNode<int>* head = NULL;
    convert(root,NULL,leaf->data,head);
    return head;
}
