void getSums(vector<int>&nums, vector<int>& ans, int i, int n,int curr = 0){
    if(i==n) return void(ans.push_back(curr));
    
    getSums(nums,ans,i+1,n,curr);
    getSums(nums,ans,i+1,n,curr+nums[i]);
}

vector<int> subsetSum(vector<int> &num){
    vector<int> ans;
    getSums(num,ans,0,num.size());
    sort(ans.begin(), ans.end());
    return ans;
}