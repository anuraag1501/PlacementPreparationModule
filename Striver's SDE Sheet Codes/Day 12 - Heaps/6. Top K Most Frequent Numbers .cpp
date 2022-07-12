#include<bits/stdc++.h>
class cmp{
    public:
        bool operator()(pair<int,int>& a, pair<int,int>&b){
            return a.first > b.first;
        }
};
vector<int> KMostFrequent(int n, int k, vector<int> &arr){
    unordered_map<int,int> mp;
    for(auto x : arr) mp[x]++;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    
    for(auto it: mp){
        pq.push({it.second,it.first});
        if(pq.size() > k) pq.pop();
    }
    vector<int> ans(k);
    while(!pq.empty()){
        ans[--k] = pq.top().second;
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}