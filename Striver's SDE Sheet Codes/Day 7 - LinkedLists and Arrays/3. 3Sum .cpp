#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int i = n-1;
    while(i>1){
        int j = 0, k = i-1, t = K - arr[i];
        while(j<k){
            if(arr[j] + arr[k] == t){
                ans.push_back({arr[j], arr[k], arr[i]});
                while(++j < k && arr[j] == arr[j-1]);
            }else if(arr[j] + arr[k] < t) j++;
            else k--;
        }
        while(--i > 1 && arr[i] == arr[i+1]);
    }
    
    return ans;
}