int longestSubSeg(vector<int> &arr , int n, int k){
    int i=0, j=-1, count = 0, ans = 0, used=0;
    
    while(++j < n){
        if(arr[j] == 0) used++;
        count++;
        
        while(used > k){
            if(arr[i] == 0) used--;
            count--,i++;
        }
        ans = max(ans, count);
    }
    return ans;
}
