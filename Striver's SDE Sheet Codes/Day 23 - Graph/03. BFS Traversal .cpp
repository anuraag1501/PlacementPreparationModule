#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    vector<vector<int>> adj(vertex);
    
    sort(edges.begin(), edges.end(), [](pair<int,int>&a, pair<int,int>&b){
        if(min(a.first,a.second) == min(b.first, b.second))
            return max(a.first,a.second) < max(b.first,b.second);
        return min(a.first,a.second) < min(b.first, b.second);
    });
    
    for(auto &x : edges){
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }
    
    vector<int> ans;
    vector<bool> vis(vertex);
    
    queue<int> q;
    q.push(0);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        if(vis[node]) z
            continue;

        ans.push_back(node);
        vis[node] = 1;

        for(auto x : adj[node]){
            if(!vis[x])
                q.push(x);
        }
    }
    for(int i=0; i<vertex; i++)
        if(!vis[i])
            ans.push_back(i);
    return ans;
}