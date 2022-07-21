#include<bits/stdc++.h>
bool dfsCheck(vector<vector<int>>&adj,  vector<int>& colour, int node,int n,int col){
   colour[node] = col;
    
    for(int j = 0; j < n; j++){
        if(!adj[node][j] && !adj[j][node])
            continue;
        if(colour[j] != -1 && colour[j] == colour[node])
            return false;
        else if(colour[j] == -1 && dfsCheck(adj,colour,j,n,1 - col) == false)
                return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n = edges.size();
    
    vector<int> colour(n,-1);
    
    for(int i = 0; i < n; i++){
        if(colour[i]==-1){
            colour[i] = 0;
            if(dfsCheck(edges,colour,i,n,0) == false)
                return false;
        }
    }
    return true;
}