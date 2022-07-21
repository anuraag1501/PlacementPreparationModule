void dfs(vector<vector<int>>&adj, vector<bool>&vis, int node, vector<int>& temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto x : adj[node]){
        if(!vis[x])
            dfs(adj,vis,x,temp);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V), ans;
    
    for(auto &x : edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    vector<bool> vis(V,false);
    
    for(int i=0; i<V; i++){
        if(vis[i])
            continue;
        
        vector<int> temp;
        dfs(adj,vis,i,temp);
        sort(temp.begin(), temp.end());

        ans.push_back(temp);
    }
    return ans;
}