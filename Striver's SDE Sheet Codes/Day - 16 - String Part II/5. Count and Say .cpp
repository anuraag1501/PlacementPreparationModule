string writeAsYouSpeak(int n) {
    string s = "1";
    
    for(int i = 1; i < n; i++){
        int cnt = 1, j = 0, l = s.length();
        string t = "";
        while(++j <= l){
            if(j==l || s[j] != s[j-1]){
                t += to_string(cnt) + s[j-1];
                cnt = 1;
            } else cnt++;
        }
        s = t;
    }
    return s;
}