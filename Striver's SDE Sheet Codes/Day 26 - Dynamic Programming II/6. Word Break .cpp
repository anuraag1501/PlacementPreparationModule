#include<unordered_map>
bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_map<string,bool> dict;
    for(auto &x : arr) dict[x] = 1;
    
    n = target.length();
    vector<int> dp(n+1);
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(!dp[j]) continue;
            if(dict[target.substr(j,i-j)]){
                dp[i] =1;
                break;
            }
        }
    }
    return dp.back();
}