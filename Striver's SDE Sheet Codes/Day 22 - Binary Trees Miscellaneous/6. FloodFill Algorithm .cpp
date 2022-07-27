#include<queue>
int a[] = {-1,0,0,1};
int b[] = {0,-1,1,0};

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor) {
    if(image[x][y] == newColor) return image;
    int n = image.size(),m=image[0].size();
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4 ;i++){
            int nx = x+a[i];
            int ny = y+b[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==image[x][y] && image[nx][ny] != newColor)
                q.push({nx,ny});
        }
        image[x][y] = newColor;
    }
    
    return image;
}