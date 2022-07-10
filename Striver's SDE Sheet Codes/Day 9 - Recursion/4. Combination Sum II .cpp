#include<algorithm>

void get(vector<vector<int>>&ans, vector<int>& temp, vector<int>&arr, int n, int k, int i=0, int currSum = 0){
    if(i==n){
        if(currSum==k) ans.push_back(temp);
        return;
    }
    
    temp.push_back(arr[i]);
    get(ans,temp,arr,n,k,i+1,currSum+arr[i]);
    temp.pop_back();
    while(++i < n && arr[i] == arr[i-1]);
    get(ans,temp,arr,n,k,i,currSum);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    
    get(ans,temp,arr,n,target);
    
    return ans;
}
