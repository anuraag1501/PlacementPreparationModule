vector<int> getPreOrderTraversal(TreeNode *root) {
    vector<int> preOrder;
    TreeNode *curr = root;
    while(curr){
        if(curr->left == NULL){
            preOrder.push_back(curr->data);
            curr = curr->right;
        } else {
            TreeNode *pre = curr->left;
            while(pre->right && pre->right != curr)
                pre = pre->right;
            if(pre->right == NULL){
                preOrder.push_back(curr->data);
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preOrder;
}