void find(TreeNode<int>* root, int t, int & ans){
    if(!root) return;
    
    if(root->val > t) find(root->left,t,ans);
    else if(root->val == t) return void(ans = t);
    else ans = root->val,find(root->right,t,ans);
    
}
int floorInBST(TreeNode<int> * root, int X) {
    int ans = -1;
    find(root,X,ans);
    return ans;
}