void bfs(int **arr, int n, int m, int i, int j){
    if(i<0 || j<0 || i==n || j==m || !arr[i][j])
        return;
    arr[i][j] = 0;
    for(int x = -1; x <= 1; x++)
        for(int y = -1; y <= 1; y++)
            bfs(arr,n,m,i+x,j+y);
}

int getTotalIslands(int** arr, int n, int m) {
    int islands = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j])
                bfs(arr,n,m,i,j),islands++;

    return islands;
}
