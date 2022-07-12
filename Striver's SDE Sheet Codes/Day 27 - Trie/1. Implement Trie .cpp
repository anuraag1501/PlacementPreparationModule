#include<unordered_map>
struct Node{
  unordered_map<char,Node*> mp;
  bool fn = 0;
};
class Trie {
    Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(auto ch : word){
            if(node->mp.find(ch) == node->mp.end())
                node->mp[ch] = new Node;
            node = node->mp[ch];
        }
        node->fn = 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;
        for(auto ch : word){
            auto it = node->mp.find(ch);
            if(it==node->mp.end())
                return false;
            node = node->mp[ch];
        }
        return node->fn;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node *node = root;
        for(auto ch : word){
            auto it = node->mp.find(ch);
            if(it==node->mp.end())
                return false;
            node = node->mp[ch];
        }
        return true;
    }
};