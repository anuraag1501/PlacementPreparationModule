bool isSafe(vector<vector<int>>&board, int i, int j, int n){
    if(i==0) return true;
    
    for(int k = i-1; k>=0; k--) if(board[k][j]) return false;
    for(int k = 1; i-k >=0 && j-k >=0; k++) if(board[i-k][j-k]) return false;
    for(int k = 1; i-k >=0 && j+k < n; k++) if(board[i-k][j+k]) return false;
    return true;
}

void solve(vector<vector<int>>& board, vector<vector<int>>& ans, int n,int i=0){
    if(i==n){
        vector<int> t;
        for(auto &x : board) for(auto y : x) t.push_back(y);
        ans.push_back(t);
        return;
    }
    for(int j=0; j<n; j++){
        if(isSafe(board,i,j,n)){
            auto b2 = board;
            b2[i][j] = 1;
            solve(b2,ans,n,i+1);
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n,vector<int>(n)), ans;
    solve(board,ans,n);
    return ans;
}