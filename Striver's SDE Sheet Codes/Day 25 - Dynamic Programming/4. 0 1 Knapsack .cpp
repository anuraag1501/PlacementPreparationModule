#include<vector>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            
			if(weights[i-1] <= j){
                int val = values[i-1] + dp[i-1][j - weights[i-1]];
                dp[i][j] = max(dp[i][j],val);
            }
        }
    }
    return dp.back().back();
}