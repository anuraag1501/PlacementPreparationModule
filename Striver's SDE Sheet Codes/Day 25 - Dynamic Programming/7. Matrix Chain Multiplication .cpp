int matrixMultiplication(vector<int> &arr, int n) {
    vector<vector<int>> dp(n-1,vector<int>(n-1,INT_MAX));
    
    for(int i = 0; i < n-1; i++)
        dp[i][i] = 0;
	
    for(int sz = 2; sz < n; sz++){
        for(int i = 0; i < n - sz; i++){
            int j = i + sz - 1;
            int mn = INT_MAX;
            for(int k = i; k < j; k++){
                mn = min(mn,
                         dp[i][k] + dp[k+1][j] + arr[i] * arr[k+1] * arr[j+1]);
            }
            dp[i][j] = mn;
        }
    }
    return dp[0].back();
}