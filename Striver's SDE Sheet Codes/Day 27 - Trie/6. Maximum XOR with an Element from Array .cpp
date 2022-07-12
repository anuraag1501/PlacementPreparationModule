#include<bits/stdc++.h>
struct Node{
    Node *ref[2] = {NULL,NULL};
};
Node *root;

void insert(int x){
    Node *node = root;
    for(int i=31; i>=0; i--){
        bool bit = ((x>>i)&1);
        if(node->ref[bit] == NULL)
            node->ref[bit] = new Node;
        node = node->ref[bit];
    }
}

int get(int x){
    int ans = 0;
    Node *node = root;
    
    for(int i=31; i>=0; i--){
        bool bit = ((x>>i)&1);
        if(node->ref[1-bit] != NULL){
            ans |= (1<<i);
            node = node->ref[1-bit];
        }
        else if(node->ref[bit] != NULL)
            node = node->ref[bit];
        else break;
    }
    return ans;
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    sort(arr.begin(), arr.end());
    for(int i=0; i<queries.size(); i++) queries[i].push_back(i);
    sort(queries.begin(), queries.end(), [](vector<int>&a, vector<int>&b){
        return b[1] ==a[1] ? a[0] < b[0] : a[1] < b[1];
    });
    
    root = new Node;
    int i=0,n=arr.size();
    vector<int> ans(queries.size());
   
    for(auto q : queries){
        while(i < n && arr[i] <= q[1])
            insert(arr[i++]);
        if(i==0) ans[q[2]]= -1;
        else ans[q[2]] = get(q[0]);
    }
    return ans;
}