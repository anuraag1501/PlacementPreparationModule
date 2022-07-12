#include<unordered_map>
struct Node{
    unordered_map<char,Node *> mp;
};
int distinctSubstring(string &word) {
    Node *root = new Node;
    int count=0, n=word.length();
    for(int i=0; i<n; i++){
        Node *node = root;
        for(int j=i; j<n; j++){
            if(node->mp.find(word[j]) == node->mp.end())
                node->mp[word[j]] = new Node, count++;
            node = node->mp[word[j]];
        }
    }
    return count;
}
