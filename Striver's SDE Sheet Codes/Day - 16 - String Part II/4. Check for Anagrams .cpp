bool areAnagram(string &str1, string &str2){
    vector<int> cnt(26);
    
    for(auto ch : str1)
        cnt[ch-'a']++;
    
    for(auto ch : str2)
        cnt[ch-'a']--;
    
    for(int i=0; i<26; i++)
        if(cnt[i])
            return false;
    return true;
}