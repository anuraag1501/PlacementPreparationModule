//Even Though it is 0(n) time and given Accepted Verdict on LeetCode, it gives TLE on CodingNinjas

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_map<int,bool> mp;
    
    for(auto x : arr) mp[x] = 1;
    
    for(auto x : arr) if(mp.find(x-1) != mp.end()) mp[x] = 0;
    
    int len = 0;
    for(int i=0; i<n; i++){
        int currLen = 1, nextElem = arr[i] + 1;
        if(mp[arr[i]]==1){
            while(mp.find(nextElem) != mp.end())
                nextElem++,currLen++;
        }
        len = max(len,currLen);
    }
    return len;
}


//Sol accepted in CodingNinjas

#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    
    int i = 1,l=1,st=0; 
    while(i<=n){
        if(i==n || (arr[i] != arr[i-1] && arr[i] != arr[i-1]+1)){
            l = max(l, arr[i-1] - arr[st] + 1);
            st = i;
        }
        i++;
    }
    return l;
}