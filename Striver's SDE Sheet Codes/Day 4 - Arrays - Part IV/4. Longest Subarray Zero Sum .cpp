#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector<int>& arr) {
    int n = arr.size();
    
    for(int i=1; i<n; i++) arr[i] += arr[i-1];
    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) ans = max(ans, i+1);
        for(int j = i+1; j<n; j++){
            if(arr[i] == arr[j])
                ans = max(ans, j-i);
        }
    }
    return ans;
}