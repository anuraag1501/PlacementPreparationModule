int maxIncreasingDumbbellsSum(vector<int> &rack, int n) {
    vector<int> dp(n);
    int ans = 0;
    
    for(int i = 0; i < n;  i++){
        int mx = 0;
        for(int j = i-1; j >= 0; j--){
            if(rack[i] > rack[j] && dp[j] > mx)
                mx = dp[j];
        }
        dp[i] = rack[i] + mx;
        ans = max(dp[i],ans);
    }
    return ans;
}