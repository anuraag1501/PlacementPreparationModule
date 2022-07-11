#include<bits/stdc++.h>
long long check(vector<int>& time, long long key){
    long long sum = 0, days = 1;
    for(auto x : time){
        if(sum + x <= key) sum += x;
        else days++,sum = x;
    }
    return days;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) {
    long long
        l = *max_element(time.begin(), time.end()),
        r = accumulate(time.begin(), time.end(), 0ll),
        ans = r;
    while(l <= r){
        long long mid = l + (r-l)/2;
        
        if(check(time,mid) <= n) ans = min(ans,mid), r = mid-1;
        else l = mid + 1;
    }
    return ans;
}