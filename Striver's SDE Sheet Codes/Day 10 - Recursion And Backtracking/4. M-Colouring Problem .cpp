#include<set>
vector<int> getAvailableColour(vector<vector<int>>& mat, vector<int>& clr, int node,int n, int m){
    set<int> pr;
    for(int i=0; i<n; i++){
        if(mat[node][i] && clr[i])
            pr.insert(clr[i]);
    }
    vector<int> c;
    for(int i=1; i<=m; i++)
        if(pr.find(i) == pr.end())
            c.push_back(i);
    return c;
}

bool colour(vector<vector<int>>& mat,vector<int> clr,int m,int n,int node){
    if(node >= n) return true;
    
    vector<int> avalClr = getAvailableColour(mat,clr,node,n,m);
    for(auto cl : avalClr){
        clr[node] = cl;
        if(colour(mat,clr,m,n,node+1))
            return true;
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    
    vector<int> clr(n);
    
    if(colour(mat,clr,m,n,0))
        return "YES";
    return "NO";
}