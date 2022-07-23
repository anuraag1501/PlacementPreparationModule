bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n+1,vector<bool>(k+1));
    
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= arr[i-1])
                dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
        }
    }
    return dp.back().back();
}