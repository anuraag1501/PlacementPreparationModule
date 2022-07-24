//PRE-ORDER TRAVERSAL BY RECURSION ---------------------------------------------------------//

void pre(vector<int>& ans, TreeNode* root){
    if(!root) return;
    
    ans.push_back(root->data);
    pre(ans, root->left);
    pre(ans, root->right);
}
vector<int> getPreOrderTraversal(TreeNode *root) {
    vector<int> ans;
    
    pre(ans,root);
    return ans;
}





//BY USING ITERATION ---------------------------------------------------------------------//

vector<int> getPreOrderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode*> st;
    
    if(root != NULL)
        st.push(root);
    
    while(!st.empty()){
        root = st.top();
        st.pop();
       
        ans.push_back(root->data);
        
        if(root->right != NULL)
            st.push(root->right);
        if(root->left != NULL)
            st.push(root->left);
    }
    return ans;
}