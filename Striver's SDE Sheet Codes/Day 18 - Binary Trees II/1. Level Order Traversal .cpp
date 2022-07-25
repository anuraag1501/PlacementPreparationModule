#include<queue>
vector<int> getLevelOrder(BinaryTreeNode<int> *root) {
    vector<int> levelOrder;
    queue<BinaryTreeNode<int>*> q;
    
    if(root)
        q.push(root);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        
        levelOrder.push_back(node->val);
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
    return levelOrder;
}