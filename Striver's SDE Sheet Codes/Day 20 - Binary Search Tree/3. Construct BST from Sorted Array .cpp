TreeNode<int>* tree(vector<int>& arr, int i, int j){
    if(i > j) return NULL;
    
    int mid = i + (j-i)/2;
    TreeNode<int>*root = new TreeNode<int>(arr[mid]);
    
    root->left = tree(arr,i,mid-1);
    root->right = tree(arr,mid+1,j);
    
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n) {
    return tree(arr,0,n-1);
}