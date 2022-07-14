#include<vector>

pair<int,int> pal(string&s, int i, int j, int n){
    while(i>=0 && j<n && s[i] == s[j]) i--,j++;
    return {i+1,j-i-1};
}

string longestPalinSubstring(string& s) {
    int n = s.length();
    pair<int,int> ans = {0,1};
    
    for(int i=1; i<n; i++){
        pair<int,int> p1,p2;
        p1 = pal(s,i,i,n);
        p2 = pal(s,i,i-1,n);
        if(p1.second < p2.second) swap(p1,p2);
        if(ans.second < p1.second) ans = p1;
    }
    
    return s.substr(ans.first,ans.second);
}