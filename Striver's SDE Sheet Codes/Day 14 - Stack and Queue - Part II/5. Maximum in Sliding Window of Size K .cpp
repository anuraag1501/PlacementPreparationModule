#include<queue>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k) {
    int n = nums.size();
    deque<int> dq;
    vector<int> ans(n-k+1);
    
    for(int i=0; i<k-1; i++){
        while(!dq.empty() && nums[dq.front()] <= nums[i])
            dq.pop_front();
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
    }
    
    for(int i=k-1; i<n;i++){
        while(!dq.empty() && (dq.front()<=i-k || nums[dq.front()] <= nums[i]))
            dq.pop_front();
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        ans[i-k+1] = nums[dq.front()];
    }
    return ans;
}