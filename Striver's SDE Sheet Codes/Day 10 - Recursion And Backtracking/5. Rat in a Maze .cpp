int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};

void solve(vector<vector<int>>& maze, vector<vector<int>>& ans, vector<vector<int>>&vis, int n, int i=0, int j=0){   
    if(i < 0 || j < 0 || i==n || j==n || vis[i][j]) return;
    
    if(i==n-1 && j==n-1){
        vector<int> v;
        vis[i][j] = 1;
        for(auto row : vis) for(auto y : row) v.push_back(y);
        ans.push_back(v);
        vis[i][j] = 0;
        return;
    }
    if(!maze[i][j]) return;
    vis[i][j] = 1;
    for(int k=0; k<4; k++){
        int nx = i+x[k];
        int ny = j+y[k];
        solve(maze,ans,vis,n,nx,ny);
    }
    vis[i][j] = 0;
}

vector<vector<int> > ratInAMaze(vector<vector<int>> &maze, int n){
    vector<vector<int>> ans, vis(n,vector<int>(n));
    maze[n-1][n-1] = 1;
    solve(maze,ans,vis,n);
    
    return ans;
}