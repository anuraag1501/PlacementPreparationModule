#include<bits/stdc++.h>
double maximumValue (vector<pair<int, int>>& items, int n, int w){
    // Write your code here.
    sort(items.begin(), items.end(), [](pair<int,int>&a, pair<int,int>& b){
       return a.second * b.first > a.first * b.second;
    });
    
    double profit = 0;
    for(int i=0; i<n && w; i++){
        int taken = min(w,items[i].first);
        profit += items[i].second * 1.0 * taken / items[i].first;
        w -= taken;
    }
    return profit;
}