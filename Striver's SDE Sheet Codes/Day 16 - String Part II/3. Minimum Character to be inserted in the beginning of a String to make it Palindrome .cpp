#include<bits/stdc++.h>
int minCharsforPalindrome(string s) {
	string t = s;
    reverse(t.begin(), t.end());
    
    t = s + '#' + t;
    int n = t.length(), mx = 0, m = s.length();
    vector<int> z(n);
    for(int i = 1,l = 0, r = 0; i < n; i++){
        if(i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while(i + z[i] < n && t[i + z[i]] == t[z[i]])
            z[i]++;
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
        if(r == n-1)
            {mx = z[i];break;}
    }
    return m - mx;
}
