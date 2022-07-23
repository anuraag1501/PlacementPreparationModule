#include<vector>
long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<long> dp(value+1);
    dp[0] = 1;
    
    for(int j = 0; j < n; j++)
        for(long i = denominations[j]; i <= value; i++)
                dp[i] += dp[i - denominations[j]];
    return dp.back();
}