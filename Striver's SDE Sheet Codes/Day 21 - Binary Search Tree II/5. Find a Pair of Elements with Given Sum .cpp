#include<set>
bool find(BinaryTreeNode<int>* root, int k,multiset<int>& st){
    if(!root) return false;
    
    if(find(root->left,k,st)) return true;
    
    if(st.find(k-root->data) != st.end()) return true;
    st.insert(root->data);
    
    return find(root->right,k,st);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k) {
    multiset<int> st;
    return find(root,k,st);
}