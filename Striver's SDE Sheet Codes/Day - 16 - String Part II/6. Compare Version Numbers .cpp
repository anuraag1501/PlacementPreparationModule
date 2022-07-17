#include<vector>
vector<string> split(string s,char c){
    vector<string> ans;
    int i=0, prev = 0, n = s.length();
    while(i <= n){
        if(i==n || s[i] == c){
            ans.push_back(s.substr(prev,i-prev));
            prev = i+1;
        }
        i++;
    }
    return ans;
}
int compareVersions(string a, string b) {
    auto v1 = split(a,'.');
    auto v2 = split(b, '.');
    
    while(v1.size() < v2.size()) v1.push_back("0");
    while(v2.size() < v1.size()) v2.push_back("0");
    
    int n = min(v1.size(), v2.size());
    
    for(int i=0; i<n; i++){
        if(v1[i].length() != v2[i].length())
            return v1[i].length() < v2[i].length() ? -1 : 1;
        for(int j=0; j<v1[i].length(); j++){
            if(v1[i][j] == v2[i][j])
                continue;
            return v1[i][j] < v2[i][j] ? -1 : 1;
        }
    }
    return 0;
}