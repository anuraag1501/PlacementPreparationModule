vector<int> nums;
string sol(int n, int k,  int fact, string curr = ""){    
    curr += to_string(nums[k/fact]);
    nums.erase(nums.begin() + (k/fact));
    
     if(nums.size() == 0) return curr;
    return sol(n,k%fact,fact/nums.size(),curr);
}
string kthPermutation(int n, int k) {
    int fact = 1;
    nums.resize(0);
    for(int i=1; i<n; i++){
        nums.push_back(i);
        fact *= i;
    }
    nums.push_back(n);
    return sol(n,k-1,fact);
}
