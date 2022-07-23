class Solution {
    vector<vector<int>> dp;
public:
    int superEggDrop(int k, int n) {
        dp = vector<vector<int>>(k+1, vector<int>(n+1,-1));
        
        return solve(k,n,dp);
    }
    int solve(int e, int f, vector<vector<int>>& dp){
        if(f==0 || f==1 || e==1) return f;
        
        if(dp[e][f] != -1) return dp[e][f];
        
        int start=1, end=f;
        int mn = INT_MAX;
        while(start<=end){
            int m = start + (end-start)/2;
            int l = solve(e-1,m-1,dp);
            int r = solve(e,f-m,dp);
            
            mn = min(mn,1 + max(l,r));
            if(l<r)
                start = m+1;
            else
                end = m-1;
        }
        return dp[e][f] = mn;
    }
};