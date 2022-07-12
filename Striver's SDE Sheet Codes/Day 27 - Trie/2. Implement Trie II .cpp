#include<unordered_map>
struct Node{
    unordered_map<char,Node*> mp;
    int prefixCount;
    int wordCount;
};
class Trie{
    Node *root;
    public:

    Trie(){
        root = new Node;
        root->prefixCount = root->wordCount = 0;
    }

    void insert(string &word){
        Node *node = root;
        for(auto ch : word){
            if(node->mp.find(ch) == node->mp.end())
                node->mp[ch] = new Node;
            node = node->mp[ch];
            node->prefixCount++;
        }
        node->wordCount++;
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(auto ch : word){
            if(node->mp.find(ch) == node->mp.end())
                return 0;
            node = node->mp[ch];
        }
        return node->wordCount;
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(auto ch : word){
            if(node->mp.find(ch) == node->mp.end())
                return 0;
            node = node->mp[ch];
        }
        return node->prefixCount;
    }
	
	// In the Question, we are Ensured that WORD to be DELETED will always be PRESENT
	//So I am not checking if word is already present
	//In case an ABSENT word is removed, RUNTIME ERROR will be given by the following function......
    void erase(string &word){
        Node *node = root;
        for(auto ch : word){
            node = node->mp[ch];
            node->prefixCount--;
        }
        node->wordCount--;
    }
};
