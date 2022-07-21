#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    vector<int> inDegree(v),topo;
    
    for(auto &x : edges){
        adj[x[0]].push_back(x[1]);
        inDegree[x[1]]++;
    }
    
    queue<int> q;
    
    for(int i=0; i<v; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto x : adj[node]){
            inDegree[x]--;
            if(inDegree[x] == 0)
                q.push(x);
        }
    }
    return topo;
}