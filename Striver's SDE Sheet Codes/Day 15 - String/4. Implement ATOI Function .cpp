int atoi(string s) {
    long ans = 0;
    bool neg = 0;
    
    for(auto ch : s){
        if(ch >= '0' && ch <= '9')
            ans = ans*10 + ch - '0';
    }
    
    if(s[0]=='-') return -ans;
    return ans;
}