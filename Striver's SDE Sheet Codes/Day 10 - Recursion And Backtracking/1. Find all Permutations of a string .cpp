void solve(string s, vector<string>& ans,string  curr = ""){
   if(s.length() == 0) return void(ans.push_back(curr));
    
    for(int i=0; i<s.length(); i++){
        string t = curr + s[i], u="";
        for(int j=0; j <i; j++) u += s[j];
        for(int j=i+1; j<s.length(); j++) u += s[j];
        solve(u,ans,t);
    }
    
}
vector<string> findPermutations(string &s) {
    vector<string> ans;
    solve(s,ans);
    return ans;
}