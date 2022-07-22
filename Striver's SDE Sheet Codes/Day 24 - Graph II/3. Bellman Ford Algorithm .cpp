int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    
    for(int i=0; i<n-1; i++)
        for(auto &x : edges)
            if(dist[x[0]] != 1e9)
                dist[x[1]] = min(dist[x[1]], x[2] + dist[x[0]]);
    
    return dist[dest];
}