#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    vector<long> pre(n), post(n);
    pre[0] = arr[0];
    post[n-1] = arr[n-1];
    
    for(int i=1; i<n; i++){
        pre[i] = max(pre[i-1], arr[i]);
        post[n-i-1] = max(post[n-i], arr[n-i-1]);
    }
    
    long ans = 0;
    
    for(int i=1; i < n-1; i++){
        if(pre[i-1] > arr[i] && post[i+1] > arr[i]){
            ans += min(pre[i-1],post[i+1]) - arr[i];
        }
    }
    return ans;
}