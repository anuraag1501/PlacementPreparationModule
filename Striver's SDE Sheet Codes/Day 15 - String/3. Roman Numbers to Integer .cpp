#include<map>

int romanToInt(string s) {
    map<char,pair<int,int>> mp;
    mp['I'] = {1,1};
    mp['V'] = {2,5};
    mp['X'] = {3,10};
    mp['L'] = {4,50};
    mp['C'] = {5,100};
    mp['D'] = {6,500};
    mp['M'] = {7,1000};
    
    int ans = mp[s.back()].second;
    for(int i=s.length()-2; i>=0; i--){
        if(mp[s[i]].first >= mp[s[i+1]].first) ans += mp[s[i]].second;
        else ans -= mp[s[i]].second;
    }
    return ans;
}
