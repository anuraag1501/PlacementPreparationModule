#include<bits/stdc++.h>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<vector<int>> meets(n,vector<int>(3));
    
    for(int i=0; i<n; i++) meets[i][0] = end[i], meets[i][2] = start[i], meets[i][1] = i+1;
    
    sort(meets.begin(), meets.end());
    
    int currEnd = -1;
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        if(meets[i][2] > currEnd){
            ans.push_back(meets[i][1]);
            currEnd = meets[i][0];
        }
    }
    return ans;
}