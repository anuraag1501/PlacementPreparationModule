bool getPath(TreeNode<int> *root, int t,vector<int>& p){
    if(!root) return false;
    
    p.push_back(root->data);
    if(root->data == t)
        return true;
    
    if(getPath(root->left,t,p))
        return true;
    if(getPath(root->right,t,p))
        return true;
    p.pop_back();
    return false;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y) {
    vector<int> p1,p2;
    getPath(root,x,p1);
    getPath(root,y,p2);

    int i = 0, n = min(p1.size(), p2.size());
    
    while(i < n && p1[i] == p2[i])
        i++;
    
    return p1[i-1];
}