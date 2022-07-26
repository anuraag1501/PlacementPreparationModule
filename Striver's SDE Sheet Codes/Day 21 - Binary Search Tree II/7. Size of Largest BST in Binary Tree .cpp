/*4 values in vetor......
                largest in substree,
                smallest in subtree,
                size,
                isBST -- if subtree is BST or NOT
*/
vector<int> find(TreeNode<int>* root, int& ans){
    if(!root) return {INT_MIN,INT_MAX,0,1};
    
    vector<int> l = find(root->left, ans);
    vector<int> r = find(root->right,ans);
    
    if(!l.back() || !r.back() || l[0] > root->data || r[1] < root->data)
        return {0,0,0,0};
    
    int mx = max(l[0],max(r[0],root->data));
    int mn = min(l[1],min(r[1],root->data));
    int sz = r[2] + l[2] + 1;
    
    ans = max(ans,sz);
    
    return {mx,mn,sz,1};
}
int largestBST(TreeNode<int>* root) {
    int ans = 0;
    find(root,ans);
    return ans;
}
