#include<map>
vector<int> countDistinctElements(vector<int> &arr, int k) {
    vector<int> ans;
    map<int,int> mp;
    
    for(int i=0; i<k; i++)
        mp[arr[i]]++;
    
    ans.push_back(mp.size());
    
    for(int i=k; i<arr.size(); i++){
        mp[arr[i]]++;
        auto it = mp.find(arr[i-k]);
        if(it->second == 1) mp.erase(it);
        else (it->second)--;
        ans.push_back(mp.size());
    }
    return ans;
}
