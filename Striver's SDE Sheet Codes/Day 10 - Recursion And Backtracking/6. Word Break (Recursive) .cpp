#include<bits/stdc++.h>
void solve(string& s, unordered_map<string,bool>& dict, vector<string>&ans,int n, int i=0,string curr = ""){
    if(i==n) return void(ans.push_back(curr));
    
    for(int j=1; j<=n-i; j++){
        if(dict[s.substr(i,j)]){
            string t;
            if(curr=="") t = s.substr(i,j);
            else t = curr + " " + s.substr(i,j);
            solve(s,dict,ans,n,i+j,t);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary){
    unordered_map<string,bool> dict;
    for(auto &x : dictionary) dict[x] = 1;
    
    vector<string> ans;
    solve(s,dict,ans,s.length());
    return ans;
}