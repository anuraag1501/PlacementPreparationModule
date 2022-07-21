#include<bits/stdc++.h>
bool bfsCheck(vector<vector<int>>&adj,  vector<int>& colour, int node,int n){
    queue<int> q;
    q.push(node);
    colour[node] = 0;
    
    while(!q.empty()){
        node = q.front();
        q.pop();
        
        for(int j=0; j < n; j++){
            if(!adj[node][j] && !adj[j][node])
                continue;
            if(colour[j] == colour[node])
                return false;
            if(colour[j] == -1)
                q.push(j);
            colour[j] = 1 - colour[node];
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n = edges.size();
    
    vector<int> colour(n,-1);
    
    for(int i = 0; i < n; i++){
        if(colour[i]==-1){
            if(bfsCheck(edges,colour,i,n) == false)
                return false;
        }
    }
    return true;
}