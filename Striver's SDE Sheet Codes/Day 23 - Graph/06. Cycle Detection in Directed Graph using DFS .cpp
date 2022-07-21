bool dfsCheck(vector<vector<int>>& adj, vector<int>& vis, int node){
    //2 means the node has been visited in the current traversal
    vis[node] = 2;
    
    for(auto &x : adj[node]){
        if(vis[x] == 2)
            return true;
        else if(dfsCheck(adj,vis,x))
                return true;
    }
    //this is to reduce time complexity....
    //so that dfs call from main function is not made "from nodes in currently visited connected components..." again
    vis[node] = 1;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> adj(n+1);
    
    for(auto &x : edges)
        adj[x.first].push_back(x.second);
    vector<int> vis(n+1);
    
    for(int i=1; i<= n; i++){
        if(!vis[i] && dfsCheck(adj,vis,i))
            return true;
    }
    return false;
}