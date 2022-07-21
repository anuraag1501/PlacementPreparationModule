#include<queue>

//USING KAHN'S ALGORITHM TO DETECT CYCLE

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> adj(n+1);
    vector<int> inDegree(n+1);
    
    for(auto &x : edges){
        adj[x.first].push_back(x.second);
        inDegree[x.second]++;
    }
    
    queue<int> q;
    int nodesVisited = 0;
    
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        nodesVisited++;
        
        for(auto x : adj[node]){
            inDegree[x]--;
            if(inDegree[x] == 0)
                q.push(x);
        }
    }
    return nodesVisited != n;
}