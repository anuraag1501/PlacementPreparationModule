#include<queue>
void connectNodes(BinaryTreeNode< int > *root) {
    queue<pair<BinaryTreeNode<int>*,int>> q;
    
    if(root)
        q.push({root,0});
    
    while(!q.empty()){
        auto node = q.front().first;
        int lev = q.front().second;
        q.pop();
        
        if(!q.empty() && q.front().second == lev)
            node->next = q.front().first;
        
        if(node->left) q.push({node->left,lev+1});
        if(node->right) q.push({node->right,lev+1});
    }
}