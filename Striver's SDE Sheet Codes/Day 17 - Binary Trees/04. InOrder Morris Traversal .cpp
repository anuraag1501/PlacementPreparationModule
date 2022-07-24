vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> inOrder;
    
    TreeNode *curr = root;
    
    while(curr){
        if(curr->left == NULL){
            inOrder.push_back(curr->data);
            curr = curr->right;
        } else {
            TreeNode *pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
            
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                inOrder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inOrder;
}