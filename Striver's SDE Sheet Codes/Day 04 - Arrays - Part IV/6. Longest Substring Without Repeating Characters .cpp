#include <bits/stdc++.h> 
int uniqueSubstrings(string& s){
    int j=0, ans = 0;
    
    vector<int> count(26);
    
    for(int i=0; i<s.length(); i++){
        count[s[i]-'a']++;
        while(count[s[i]-'a'] > 1) count[s[j++]-'a']--;
        ans = max(ans, i-j+1);
    }
    return ans;
}