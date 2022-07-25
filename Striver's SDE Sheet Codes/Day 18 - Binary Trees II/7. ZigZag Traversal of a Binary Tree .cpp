vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    vector<vector<int>> levelWise;
    
    queue<pair<BinaryTreeNode<int>*,int>> q;
    if(root)
        q.push({root,0});
    while(!q.empty()){
        auto node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if(levelWise.size() == level)
            levelWise.push_back({});
        
        levelWise[level].push_back(node->data);
        
        if(node->left)
            q.push({node->left,level+1});
        if(node->right)
            q.push({node->right,level+1});
    }
    vector<int> zigzag;
    
    int n = levelWise.size();
    
    for(int i = 0; i < n; i++){
        if(i%2)
            zigzag.insert(zigzag.end()
                         ,levelWise[i].rbegin()
                         ,levelWise[i].rend());
        else
            zigzag.insert(zigzag.end()
                         ,levelWise[i].begin()
                         ,levelWise[i].end());
    }
    return zigzag;
}
