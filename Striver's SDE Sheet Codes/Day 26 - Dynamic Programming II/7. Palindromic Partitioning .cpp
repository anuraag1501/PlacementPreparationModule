#include<vector>
int palindromePartitioning(string s) {
    int n=s.length();
    
    //vector to store if string starting from ith to jth index is palindrome or not
    vector<vector<bool>> isPal(n,vector<bool>(n));
    
    //len is equal to current substring length - 1
    for(int len = 0; len < n; len++){
        for(int i = 0; i < n - len; i++){
            if(len == 0)
                isPal[i][i] = 1;
            else  if(len == 1)
                isPal[i][i+len] = s[i] == s[i+len];
            else 
                isPal[i][i+len] = (s[i] == s[i+len] && isPal[i+1][i+len-1]);
        }
    }
    
    vector<vector<int>> dp(n,vector<int>(n));
    
    //i + len gives last index (0 base)....len is 1 less than actual len of substring
    for(int len = 1; len < n; len++){
        for(int i = 0; i < n - len; i++){
            //max str len = 100, so at most will be 99 cuts
            dp[i][i+len] = 1000;
            if(isPal[i][i+len])
                dp[i][i+len] = 0;
            else {
                for(int j = i; j < i+len; j++){
                    dp[i][i+len] = min(dp[i][i+len], 1 + dp[i][j] + dp[j+1][i+len]);
                }
            }
        }
    }
    return dp[0].back();
}
