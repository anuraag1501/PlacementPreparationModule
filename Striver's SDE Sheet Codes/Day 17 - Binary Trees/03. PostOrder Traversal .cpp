//PRE-ORDER TRAVERSAL BY RECURSION ---------------------------------------------------------//

void post(vector<int>&ans, TreeNode* root){
    if(!root) return;
    
    post(ans,root->left);
    post(ans,root->right);
    ans.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root) {
    vector<int> ans;
    post(ans, root);
}
    return ans;
	




//BY USING ITERATION ---------------------------------------------------------------------//

vector<int> getPostOrderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode *prev=NULL;
        
    while(!st.empty() || root){
        while(root){
            st.push(root);
            root = root->left;
        }
        root = st.top();
        
		//if there is no righ subtree or right subtree has already been visited......
        if(!root->right || root->right == prev){
            ans.push_back(root->data);
            st.pop();
            prev = root;
            root = NULL;
        } else {
            root =  root->right;
        }
    }
    return ans;
}