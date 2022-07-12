#include<unordered_map>
struct Node{
    unordered_map<int,Node*> ref;
};
Node *root;
void insert(long x){
    Node *node = root;
    for(int i=31; i>=0; i--){
        bool bit = ((1ll<<i)&x);
        if(node->ref.find(bit)==node->ref.end())
            node->ref[bit] = new Node;
        node = node->ref[bit];
    }
}
long get(long x){
    Node *node = root;
    long ans = 0;
    for(int i=31; i>=0 ; i--){
        bool bit =  ((1ll<<i)&x);
        if(node->ref.find(1-bit) !=node->ref.end()){
            ans |= (1<<i);
            node = node->ref[1 - bit];
        }
        else if(node->ref.find(bit) !=node->ref.end())
            node = node->ref[bit];
        else break;
    }
    return ans;
}
int maximumXor(vector<int>& a){
    root = new Node;
    for(auto x : a) insert(x);
    long ans = 0;
    for(auto x : a){
        ans = max(ans,get(x));
    }
    return (int)ans;
}