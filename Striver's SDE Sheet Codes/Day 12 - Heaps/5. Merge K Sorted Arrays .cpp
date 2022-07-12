#include<queue>
#define ppii pair<int,pair<int,int>>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    priority_queue<ppii,vector<ppii>, greater<ppii>> pq;
    int tot = 0,id=0;
    
    for(int i=0; i<k; i++){
        pq.push({kArrays[i][0],{i,1}});
        tot += kArrays[i].size();
    }
    
    vector<int> ans(tot);
    
    while(!pq.empty()){
        ppii tp = pq.top();
        pq.pop();
        
        int elem = tp.first;
        int i = tp.second.first;
        int num = tp.second.second;
        
        ans[id++] = elem;
        if(kArrays[i].size() > num)
            pq.push({kArrays[i][num],{i,num+1}});
    }
    return ans;
}
