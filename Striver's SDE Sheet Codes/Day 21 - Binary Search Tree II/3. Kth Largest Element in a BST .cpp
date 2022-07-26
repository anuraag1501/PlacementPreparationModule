void find(TreeNode<int>*root,int k,int& ans,int& currVis){
    if(!root || currVis > k) return;
    
    find(root->right,k,ans,currVis);
    
    currVis++;
    if(currVis == k){
        ans = root->data;
        currVis++;
        return;
    }

    find(root->left,k,ans,currVis);
}
int KthLargestNumber(TreeNode<int>* root, int k) {
    int ans = -1,currVis=0;
    find(root,k,ans,currVis);
    return ans;
}
