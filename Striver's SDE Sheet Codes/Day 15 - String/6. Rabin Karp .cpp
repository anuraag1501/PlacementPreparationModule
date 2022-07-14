#define mod 1000000007
long pw (long a, long x){
    long ans = 1;
    while(x){
        if(x%2) ans  = (ans*a)%mod;
        a = (a*a)%mod;
        x /= 2;
    }
    return ans;
}
vector<int> stringMatch(string &s, string &pat) {
    long desiredHash = 0,
        n = s.length(),
        m = pat.length(),
        curr = 0,
        mx = pw(27,m-1);
    if(m>n) return {};
    for(auto ch : pat)
        desiredHash = (desiredHash *27 + ch-'A' + 1)%mod;
    
    for(int i=0; i<m; i++){
        curr = (curr * 27 + s[i] - 'A'+1)%mod;
    }
    vector<int> ans;
    for(int i=m; i<= n; i++){
        if(curr == desiredHash){
            bool f=1;
            for(int j=0; j<m; j++){
                if(pat[j] != s[i-m+j]){
                    f=0;
                    break;
                }
            }
            if(f) ans.push_back(i-m);
        }
        if(i==n) break;
        curr = (curr - (mx * (s[i-m]-'A' + 1))%mod + mod)%mod;
        curr = (curr * 27 + s[i] - 'A' + 1) %mod;
    }
    return ans;
}
