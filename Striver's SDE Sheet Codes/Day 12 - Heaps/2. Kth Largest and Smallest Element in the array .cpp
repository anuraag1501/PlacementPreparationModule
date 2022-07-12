#include<queue>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k){
    priority_queue<int> lrg;
    priority_queue<int,vector<int>,greater<int>> sml;
    
    for(auto x : arr){
        lrg.push(x);
        sml.push(x);
        if(lrg.size() > k) lrg.pop();
        if(sml.size() > k) sml.pop();
    }
    return {lrg.top(),sml.top()};
}