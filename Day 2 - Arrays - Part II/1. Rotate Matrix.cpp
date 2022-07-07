void rotateMatrix(vector<vector<int>> &mat, int n, int m){
    int s = min(n,m)/2;
    for(int i = 0; i < s; i++){
        int curr = mat[i][i];
        for(int j = i; j < n - i - 1; j++)
            mat[j][i] = mat[j+1][i];
 
        for(int j = i; j < m - i - 1; j++)
            mat[n-i-1][j] = mat[n-i-1][j+1];
        
        for(int j = n-i-1; j > i; j--)
            mat[j][m-i-1] = mat[j-1][m-i-1];
        
        for(int j = m-i-1; j>i+1; j--)
            mat[i][j] = mat[i][j-1];
        mat[i][i+1] = curr;
    }
}