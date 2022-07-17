int zAlgorithm(string s, string p, int n, int m) {
     s = p + '#' + s;
    
    vector<int> z(s.size());
    int  ans = 0;
    for(int i = 1, l = 0,r = 0; i < s.length(); i++){
        if(i<=r)
            z[i] = min(r-i+1, z[i-l]);
        while(i + z[i] < s.length() && s[z[i]] == s[i+z[i]] )
            z[i]++;
        if(r < z[i] + i - 1){
            l = i;
            r = i + z[i] - 1;
        }
        if(z[i] == m) ans++;
    }
    return ans;
}