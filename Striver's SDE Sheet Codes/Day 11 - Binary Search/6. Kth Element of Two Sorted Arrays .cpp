int uBound(vector<int>& arr, int key){
    if(key >= arr.back()) return arr.size();
    if(key < arr[0]) return 0;
    int l = 0, r = arr.size()-1;
    
    while(l < r){
        int m = l + (r-l)/2;
        if(arr[m] <= key) l = m+1;
        else r = m;
    }
    return l;
}

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int 
        ans = 1e5,
        l = 0,
        r = 1e5;
    k--;
    
    while(l <= r){
        int mid = l + (r-l)/2;
        int count = uBound(row1,mid) + uBound(row2,mid);
        
        if(count <= k) l = mid+1;
        else ans = min(ans,mid), r=mid-1;
    }
    return ans;
}