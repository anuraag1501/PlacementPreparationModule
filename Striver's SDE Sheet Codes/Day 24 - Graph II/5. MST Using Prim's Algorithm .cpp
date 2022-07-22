#include<bits/stdc++.h>
class cmp{
    public:
        bool operator()(pair<pair<int,int>,int>& a,pair<pair<int,int>,int>& b){
            return a.second > b.second;
        }
};
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    vector<vector<int>> adj(n+1,vector<int>(n+1,1e9));
    
    for(auto &x : g){
        adj[x.first.first][x.first.second] = 
            min(adj[x.first.first][x.first.second],x.second);
        adj[x.first.second][x.first.first] = adj[x.first.first][x.first.second];
    }
    
    for(int i = 1; i <= n; i++)
        adj[i][i] = 1e9;
    
    vector<pair<pair<int,int>, int>> ans;
    
    priority_queue< pair<pair<int,int>,int>,
                    vector<pair<pair<int,int>,int>>,
                    cmp > pq;
    for(int j = 1; j <= n; j++){
        if(adj[g[0].first.first][j] != 1e9)
            pq.push({{g[0].first.first,j},adj[g[0].first.first][j]});
    }
    
    vector<bool> vis(n+1);
    
    while(!pq.empty()){
        int a = pq.top().first.first;
        int b = pq.top().first.second;
        int w = pq.top().second;

        if(!vis[a] || !vis[b])
            ans.push_back(pq.top());
        pq.pop();
        
        if(!vis[a]){
            for(int j = 1; j <= n; j++){
                if(adj[a][j] != 1e9)
                pq.push({{a,j},adj[a][j]});
            }
        }
        if(!vis[b]){
            for(int j = 1; j <= n; j++){
                if(adj[b][j] != 1e9)
                pq.push({{b,j},adj[b][j]});
            }
        }
        vis[a] = vis[b] = 1;
    }
    return ans;
}
