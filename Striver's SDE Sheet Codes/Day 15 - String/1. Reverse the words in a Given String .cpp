#include<vector>
string reverseString(string str) {
    string curr = "";
    int i=0, n = str.length();
    vector<string> v;
    while(i<=n){
        if(i==n || str[i] == ' '){
            if(curr.length() > 0)v.push_back(curr);
            curr = "";
        }
        else curr += str[i];
        i++;
    }
    curr = v.back();
    for(int i=v.size()-2; i>=0; i--) curr += " " + v[i];
    return curr;
}