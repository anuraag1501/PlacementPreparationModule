bool dfsCycleCheck(vector<vector<int>>& adj, vector<int>&par, int node,int p){
    par[node] = p;
    
    for(auto &x : adj[node]){
        if(!par[x]){
            if(dfsCycleCheck(adj,par,x,node))
                return true;
        } else {
            //if x is root || x is visited coz it is the parent of current node......
            if(par[x] == -1 || (par[x] && par[node] == x))
                continue;
            else return true;
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
    //parent[i] == 0 indicates unvisited and -1 indicates root
    vector<int> par(n+1,0);
    
    for(int i=1; i<=n; i++){
        if(!par[i] && dfsCycleCheck(adj,par,i,-1))
            return "Yes";
    }
    return "No";
}
