void find(BinaryTreeNode<int>* root, int k, int & ans){
    if(!root) return;
    
    if(root->data == k) return void(ans = k);
    else if(root->data < k) find(root->right,k,ans);
    else ans = root->data,find(root->left,k,ans);
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = -1;
    find(node,x,ans);
    return ans;
}