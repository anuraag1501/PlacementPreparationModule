long long maxSubarraySum(int arr[], int n){
    long long ans=0,curr=0;
    
    for(int i = 0; i < n; i++){
        curr += arr[i];
        ans = max(ans,curr);
        if(curr < 0) curr = 0;
    }
    return ans;
}