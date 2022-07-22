//KOSARAJU ALGORITHM FOR STRONGLY CONNECTED COMPONENTS

void dfs(vector<vector<int>>& g, vector<bool>& vis, vector<int>& v, int i){
    vis[i] = 1;
    for(auto x : g[i])
        if(!vis[x])
            dfs(g,vis,v,x);
    v.push_back(i);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n), rg(n),ans;
    
    for(auto &x : edges){
        g[x[0]].push_back(x[1]);
        rg[x[1]].push_back(x[0]);
    }
    
    vector<int> v;
    vector<bool> vis(n);
    
    for(int i = 0; i < n; i++)
        if(!vis[i])
            dfs(g,vis,v,i);
    
    vis.assign(n,0);
    while(!v.empty()){
        if(vis[v.back()]){
            v.pop_back();
            continue;
        }
        vector<int> tmp;
        dfs(rg,vis,tmp,v.back());
        ans.push_back(tmp);
        v.pop_back();
    }
    return ans;
}