#include<map>
#include<set>

struct Node{
    int key,val,f;
    Node *prev, *next;
    Node(int k,int v,int x){
        key = k;
        val = v;
        f = x;
        prev = next = NULL;
    }
};

class cmp{
    public:
        bool operator()(Node* a, Node *b){
            return a->f < b->f;
        }
};

class LFUCache
{
    map<int,Node*> mp;
    set<Node*,cmp> frq;
    int sz;
public:
    LFUCache(int capacity){
        sz = capacity;
    }

    int get(int key){
        auto it = mp.find(key);
        if(it == mp.end())
            return -1;
        Node *node = it->second;
        int k = node->key,v = node->val, f = 1+node->f;
        del(node);
        insert(k,v,f);
        return v;
    }
    
    void del(Node *node){
        mp.erase(node->key);
        frq.erase(node);
        delete(node);
    }
    
    void insert(int key, int val, int fr){
        Node *node = new Node(key,val,fr);
        frq.insert(node);
        mp[key] = node;
    }
    
    void put(int key, int value){
        auto it = mp.find(key);
        int f=1;
        if(it != mp.end())
            del(it->second),f += it->second->f;
        
        if(mp.size()==sz)
            del(*frq.begin());
        
        insert(key,value,f);
    }
};
