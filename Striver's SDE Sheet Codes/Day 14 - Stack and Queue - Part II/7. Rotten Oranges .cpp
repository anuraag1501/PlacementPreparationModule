#include<bits/stdc++.h>
int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};

int minTimeToRot(vector<vector<int>>& grid, int n, int m) {
    int fresh = 0, ans = 0;
    queue<tuple<int,int,int>> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 2)
                q.push(make_tuple(i,j,0));
            else if(grid[i][j] == 1) fresh++;
        }
    }
    
    while(!q.empty()){
        for(int id=0; id<q.size(); id++){
            int i,j,c;
            tie(i,j,c) = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int nx = i+x[k];
                int ny = j+y[k];
                
                if(nx<0||ny<0||nx==n||ny==m||grid[nx][ny]!=1)
                    continue;
                grid[nx][ny] = 2;
                ans = max(ans,c+1);
                q.push(make_tuple(nx,ny,c+1));
                fresh--;
            }
        }
    }
    if(fresh) return -1;
    return ans;
}