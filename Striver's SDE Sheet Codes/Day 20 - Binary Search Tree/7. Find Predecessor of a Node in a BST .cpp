void find(BinaryTreeNode<int>* root,int key , pair<int,int>& p){
    if(!root) return;
    
    if(root->data > key){
        p.second = root->data;
        find(root->left,key,p);
    } else if(root->data < key) {
        p.first = root->data;
        find(root->right,key,p);
    } else {
        find(root->right,key,p);
        find(root->left,key,p);
    }
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    pair<int,int> p{-1,-1};
    find(root,key,p);
    return p;
}
