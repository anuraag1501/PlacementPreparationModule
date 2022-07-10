#include<bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs){
    sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    });
    
    int mx = 0;
    for(int i = 0; i < jobs.size(); i++) mx = max(mx, jobs[i][0]);
    
    vector<int> vis(mx+1);
    
    for(int i = 0; i < jobs.size(); i++){
        while(jobs[i][0] > 0 && vis[jobs[i][0]])
            jobs[i][0]--;
        if(jobs[i][0])
            vis[jobs[i][0]] = jobs[i][1];
    }
    return accumulate(vis.begin(), vis.end(), 0);
}
