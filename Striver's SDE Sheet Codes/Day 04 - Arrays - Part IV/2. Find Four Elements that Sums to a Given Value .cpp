#include <bits/stdc++.h> 
string fourSum(vector<int>& arr, long long target, int n){
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int l = j+1, r = n-1;
            long long t = (long long)target - arr[i] - arr[j];
            while(l < r){
                long long s = arr[l];
                s += arr[r];
                if(s == t) return "Yes";
                
                if(s > t) r--;
                else l++;
            }
        }
    }
    return "No";
}