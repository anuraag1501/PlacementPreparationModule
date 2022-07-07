void setZeros(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();
    
    bool zr=0,zc=0;
    for(int i=0; i<n; i++) if(mat[i][0]==0) zc=1;
    for(int i=0; i<m; i++) if(mat[0][i]==0) zr=1;
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(mat[i][j]==0){
                mat[i][0] = mat[0][j] = 0;
            }
        }
    }
    
    for(int i=1; i<n; i++)
        if(mat[i][0]==0)
            for(int j=1; j<m; j++)
                mat[i][j] = 0;
    for(int j=1; j<m; j++)
        if(mat[0][j]==0)
            for(int i=1; i<n;i++)
                mat[i][j] = 0;
    
    if(zr) for(int j = 0; j < m; j++) mat[0][j] = 0;
    if(zc) for(int i = 0; i < n; i++) mat[i][0] = 0;
}