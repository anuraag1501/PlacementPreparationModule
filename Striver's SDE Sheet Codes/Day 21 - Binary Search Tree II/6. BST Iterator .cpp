#include<stack>
class BSTiterator
{  
    stack<TreeNode<int>*> st;
    TreeNode<int>* root;
    
	BSTiterator(TreeNode<int> *root)
    {
        this->root = root;
    }

    int next()
    {
       while(root){
           st.push(root);
           root = root->left;
       }
        int data = st.top()->data;
        root = st.top()->right;
        st.pop();
        return data;
    }

    bool hasNext()
    {
        return ((st.size() > 0) || root);
    }
};