int solve(vector<vector<int>>& dp, string& s, string& t, int i, int j){
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int mn = 1e8;
    if(s[i]==t[j]) mn = solve(dp,s,t,i-1,j-1);
        
    else{
        mn = min(mn, 1 + solve(dp,s,t,i-1,j-1));    //replacing a character
        mn = min(mn,1 + solve(dp,s,t,i-1,j));       //deleting from s
        mn = min(mn, 1 + solve(dp,s,t,i,j-1));      //deleting from t
    }
    return dp[i][j] = mn;
}

int editDistance(string str1, string str2) {
    int n = str1.length(), m = str2.length();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(dp,str1,str2,n-1,m-1);
}