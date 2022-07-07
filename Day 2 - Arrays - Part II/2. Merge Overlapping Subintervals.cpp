vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end());
    
    int begin = intervals[0][0], end = intervals[0][1];
    vector<vector<int>> ans;
    int i=0, n = intervals.size();
    
    while(++i<=n){
        if(i==n || intervals[i][0] > end){
            ans.push_back({begin,end});
            if(i==n) break;
            begin = intervals[i][0],end = intervals[i][1];
        }else{
            if(intervals[i][1]>end) end = intervals[i][1];
        }
    }
    return ans;
}
