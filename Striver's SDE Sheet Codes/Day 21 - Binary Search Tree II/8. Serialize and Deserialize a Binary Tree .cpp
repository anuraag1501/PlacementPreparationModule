/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> split(string& s, char ch){
    int i = -1, n = s.length();
    
    if(n==0) return {};
    
    string curr = "";
    vector<int> ans;
    
    while(++i <= n){
        if(i==n || s[i] == ch){
            ans.push_back(stoi(curr));
            curr = "";
        } else curr += s[i];
    }
    return ans;
}

string serializeTree(TreeNode<int> *root) {
    if(!root) return "-1";
    
    string l = serializeTree(root->left);
    string r = serializeTree(root->right);
   
    return to_string(root->data) + " "  + l + " " + r;
}

TreeNode<int>* tree(vector<int>&nums, int& i, int n){
    if(i==n || nums[i] == -1){
        i++;
        return NULL;
    }
    
    TreeNode<int>* root = new TreeNode<int>(nums[i++]);
    root->left = tree(nums,i,n);
    root->right = tree(nums,i,n);
    
    return root;
}


TreeNode<int>* deserializeTree(string& ser) {
    vector<int> nums = split(ser,' ');
    int i = 0, n = nums.size();
    return tree(nums,i,n);
}