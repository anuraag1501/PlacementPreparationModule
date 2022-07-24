//BY USING RECURSION

void get(vector<int>&inOrder, TreeNode* root){
    if(!root) return;
    
    get(inOrder,root->left);
    
    inOrder.push_back(root->data);
    
    get(inOrder, root->right);
}
vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> inOrder;
    get(inOrder,root);
    return inOrder;
}




//BY USING ITERATION

vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> inOrder;
    stack<TreeNode *> st;
    
    while(!st.empty() || root){
        while(root){
            st.push(root);
            root = root->left;
        }
        inOrder.push_back(st.top()->data);
        root = st.top()->right;
        st.pop();
    }
    return inOrder;
}