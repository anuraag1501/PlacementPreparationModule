#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x){
    unordered_map<int,int> mp;
    int count = 0,curr=0;
    
    // prefix xor at some point become equal to x
    mp[0] = 1;
    
    
    for(auto a : arr){
        curr ^= a;

        count += mp[curr^x];
        mp[curr]++;
    }
    return count;
}