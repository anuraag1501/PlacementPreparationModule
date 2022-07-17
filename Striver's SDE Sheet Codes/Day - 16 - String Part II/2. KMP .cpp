bool findPattern(string p, string s) {
    s = p + '#' + s;
    int m = p.length(), n = s.length();
    
    vector<int> kmp(n);

    for(int i=1; i<n; i++){
        int prev = kmp[i-1];
        while(prev > 0 && s[i] != s[prev])
            prev = kmp[prev-1];
        if(s[i] == s[prev])
            prev++;
        kmp[i] = prev;
        if(kmp[i] == m) return true;
    }
    return false;
}