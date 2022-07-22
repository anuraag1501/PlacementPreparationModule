#include<bits/stdc++.h>

//Comparator for Priority_Queue
class cmp{
    public:
        bool operator()(vector<int>&a, vector<int>& b){
            return a[2] > b[2];
        }
};

//Structure for DISJOINT Set
struct DS{
    int node;
    int rank;
};

//function to find the parent of the node in the disjoint set
int find(vector<int>& par, int i){
    if(par[i] == -1)
        return i;
    return par[i] = find(par,par[i]);
}

//creating union of two set
void ds_union(vector<int> &par, struct DS &x,struct DS &y){
    if(x.rank > y.rank)
        par[y.node] = x.node; 
    else if(x.rank < y.rank)
        par[x.node] = y.node;
    else
        par[y.node] = x.node, x.rank++;
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    priority_queue<vector<int>, vector<vector<int>>, cmp > pq;
    for(auto &x : graph)
        pq.push(x);
    
    vector<int> par(n+1,-1);
    int cost = 0;
    
    //creating disjoint set of n nodes
    struct DS ds[n+1];
    for(int i = 1; i <= n; i++)
        ds[i].node = i,ds[i].rank = 0;
    
    while(!pq.empty()){
        auto edge = pq.top();
        pq.pop();
        
        int p1 = find(par,edge[0]);    
        int p2 = find(par,edge[1]);
        
        if(p1 != p2){
            cost += edge[2];
            ds_union(par,ds[p1],ds[p2]);
        }
    }
    return cost;
}