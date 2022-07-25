void getLeftView(TreeNode<int>* root, vector<int>& v){
   queue<pair<TreeNode<int>*,int>> q;
    if(root)
        q.push({root,1});
    
    while(!q.empty()){
        auto node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if(!node->left && !node->right)
            continue;
        
        if( v.size() == level)
            v.push_back(node->data);
        
        if(node->left)
            q.push({node->left,level+1});
        else if(node->right)
            q.push({node->right,level+1});
    }
}


void getLeaves(TreeNode<int>* root, vector<int>& boundary){
    if(!root) return;
    
    if(!root->right && !root->left)
        return void(boundary.push_back(root->data));
    
    getLeaves(root->left,boundary);
    getLeaves(root->right,boundary);
}



void getRightView(TreeNode<int>* root, vector<int>& v){
    vector<int> tmp;
    queue<pair<TreeNode<int>*,int>> q;
    
    if(root)
        q.push({root,0});
    
    while(!q.empty()){
        auto node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if(!node->left && !node->right) continue;
        
        if(tmp.size() == level)
            tmp.push_back(node->data);
        
        if(node->right)
            q.push({node->right,level+1});
        else if(node->left)
            q.push({node->left,level+1});
    }
    v.insert(v.end(),tmp.rbegin(),tmp.rend());
}

vector<int> traverseBoundary(TreeNode<int>* root) {
    vector<int> boundary;
    if(!root) return boundary;
    
    boundary.push_back(root->data);

    getLeftView(root->left,boundary);
    getLeaves(root->left,boundary);
    getLeaves(root->right,boundary);
    getRightView(root->right,boundary);
    
    return boundary;
}