void mirror(Node* node) {
        convert(node->right,node->left);
    }
    void convert(Node* &left, Node* &right){
        
        swap(left,right);
        if(left) convert(left->left,left->right);
        if(right) convert(right->left,right->right);
    }