#include<algorithm>
#include<stack>
void topoSort(vector<vector<int>>& adj, vector<bool>& vis,vector<int>& ans, int node){
    vis[node] = 1;
    
    for(auto &x : adj[node])
        if(!vis[x])
            topoSort(adj,vis,ans,x);
    ans.push_back(node);        
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    vector<int> ans;
    
    for(auto &x : edges)
        adj[x[0]].push_back(x[1]);
    
    vector<bool> vis(v);
    
    for(int i=0; i<v; i++){
        if(!vis[i])
            topoSort(adj,vis,ans,i);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}