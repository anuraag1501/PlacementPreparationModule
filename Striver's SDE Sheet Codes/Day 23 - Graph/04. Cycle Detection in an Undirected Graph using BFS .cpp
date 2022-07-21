#include<queue>
bool bfsCycleCheck(vector<vector<int>>& adj, vector<bool>&vis, int node){
    queue<int> q;
    q.push(node);
    
    while(!q.empty()){
        node = q.front();
        q.pop();
        
        if(vis[node])
            return true;
        vis[node] = 1;
        for(auto &x : adj[node]){
            if(!vis[x])
                q.push(x);
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    vector<vector<int>> adj(n+1);
    
    for(auto &x : edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    vector<bool> vis(n+1);
    
    for(int i=1; i<=n; i++){
        if(!vis[i] && bfsCycleCheck(adj,vis,i))
            return "Yes";
    }
    return "No";
}
