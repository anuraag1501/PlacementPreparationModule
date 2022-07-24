#include<stack>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
    vector<vector<int>> traversals(3);
    stack<pair<BinaryTreeNode<int>*,int>> st;
    
    if(root)
        st.push({root,0});
    while(!st.empty()){
        auto node = st.top().first;
        int vis = st.top().second;
        st.pop();
        
        switch(vis){
            case 0: 
                    traversals[1].push_back(node->data);
                    st.push({node,1});
                    if(node->left) st.push({node->left,0});
                    break;
            case 1: 
                    traversals[0].push_back(node->data);
                    st.push({node,2});
                    if(node->right) st.push({node->right,0});
                    break;
            case 2:
                    traversals[2].push_back(node->data);
        }
    }
    return traversals;
}