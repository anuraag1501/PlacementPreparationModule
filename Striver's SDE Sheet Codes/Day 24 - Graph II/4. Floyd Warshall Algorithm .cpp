int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n+1,vector<int>(n+1,1e9));
    
    for(auto &x : edges)
        adj[x[0]][x[1]] = x[2];
    
    for(int i = 0; i <= n; i++) adj[i][i] = 0;
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][k] == 1e9 || adj[k][j] == 1e9)
                    continue;
                int curr = adj[i][k] + adj[k][j];
                if(curr < adj[i][j])
                    adj[i][j] = curr;
            }
        }
    }
    return adj[src][dest];
}