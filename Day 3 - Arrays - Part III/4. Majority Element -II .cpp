#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr){
    if(arr.size()<3) return arr;
    vector<int> ans;
    sort(arr.begin(), arr.end());
    int count = 1, n = arr.size();
    
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1])
            count++;
        else count = 1;
        if(count > n/3){
            ans.push_back(arr[i]);
            while(i<n-1 && arr[i] == arr[i+1])
                i++;
            count = 1;
        }
    }
    return ans;
}