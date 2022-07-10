#include<algorithm>
void getTargetSumSubsets(vector<int>& arr, vector<vector<int>>&ans, vector<int>&temp, int n, int k, int i=0,int currSum=0){
    if(i==n){
        if(currSum == k) ans.push_back(temp);
        return;
    }
    
    temp.push_back(arr[i]);
    getTargetSumSubsets(arr,ans,temp,n,k,i+1,currSum+arr[i]);
    temp.pop_back();
    getTargetSumSubsets(arr,ans,temp,n,k,++i,currSum);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k){
    vector<vector<int>> ans;
    vector<int> temp;
    getTargetSumSubsets(arr,ans,temp,n,k);
    return ans;
}