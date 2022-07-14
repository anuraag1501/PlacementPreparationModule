#include<unordered_map>
struct Node{
    int key,val;
    Node *prev,*next;
    Node(int k,int n){
        key = k;
        val = n;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
    Node *head,*tail;
    int sz,currSize;
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity){
        sz = capacity;
        currSize=0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        auto it = mp.find(key);
        if(it==mp.end())
            return -1;
        int val = it->second->val;
        del(it->second,key);
        insert(key,val);
        return val;
    }
    void del(Node *nd,int key){
         nd->prev->next = nd->next;
         nd->next->prev = nd->prev;
         delete(nd);
         mp.erase(key);
         currSize--;
    }
    
    void insert(int key,int val){
        Node *curr = new Node(key,val);
        mp[key] = curr;
        curr->next = head->next;
        curr->prev = head;
        curr->next->prev = curr;
        head->next = curr;
        currSize++;
    }
    
    void put(int key, int val){
        auto it = mp.find(key);
        if(it != mp.end())
            del(it->second,key);

        if(currSize == sz){
            del(tail->prev,tail->prev->key);
        }
        insert(key,val);
    }
};
