bool pal(string s){
    int i=0 , j = s.length() - 1;
    while(i < j) if(s[i++] != s[j--]) return false;
    return true;
}
void get(string&s,vector<vector<string>>&ans,vector<string>&temp,int n,int i){
    if(i>=n) return void(ans.push_back(temp));
    
    for(int j = 1; j <= n-i; j++){
        if( pal(s.substr(i,j)) ){
            temp.push_back(s.substr(i,j));
            get(s,ans,temp,n,i+j);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s){
    vector<vector<string>> ans;
    vector<string> temp;
    get(s,ans,temp,s.length(),0);
    
    return ans;
}