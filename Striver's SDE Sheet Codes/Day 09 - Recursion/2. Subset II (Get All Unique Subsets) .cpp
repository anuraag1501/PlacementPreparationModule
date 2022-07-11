#include<algorithm>
void getUniqueSubsets(vector<int>&arr, vector<vector<int>>& ans, vector<int>&temp, int n, int i=0){
    if(i==n) return void(ans.push_back(temp));
    
    temp.push_back(arr[i++]);
    getUniqueSubsets(arr,ans,temp,n,i);
    
    temp.pop_back();
    while(i<n && arr[i] == arr[i-1]) i++;
    getUniqueSubsets(arr,ans,temp,n,i);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    vector<vector<int>> ans;
    vector<int>  temp;
    sort(arr.begin(), arr.end());
    
    getUniqueSubsets(arr,ans,temp,n);
    sort(ans.begin(), ans.end());
    return ans;
}