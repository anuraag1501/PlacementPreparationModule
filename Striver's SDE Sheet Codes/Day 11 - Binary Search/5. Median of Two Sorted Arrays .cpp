//the function uBound given same output as we will get using STL Function as --
// upper_bound(arr.begin(), arr.end(), key) - arr.begin()

int uBound(vector<int>& arr, long long key){
    if(key >= arr.back()) return arr.size();
    int l = 0, r = arr.size()-1;
    while(l<r){
        int m = l + (r-l)/2;
        if(arr[m] <= key) l = m+1;
        else r = m;
    }
    return l;
}

double median(vector<int>& a, vector<int>& b){
    long long 
              l=1,
              r=1e9,
              sz = 0ll + a.size() + b.size();
    double 
              ans = 1e9;
    long long 
              medIndex = (sz - 1)/2,
              med1=1e9,
              med2=1e9;
    
    while(l<=r){
        long long m = l + (r-l)/2;
        long long count = 0ll + uBound(a,m) + uBound(b,m);
        
        if(count <= medIndex) l = m+1;
        else med1 = min(med1,m), r=m-1;
    }
    
    //if total size of two array is odd, then there will be only one middle element
    if(sz%2) return med1;
    
    //finding second median for even sized array......
    medIndex = (sz/2);
    l=1, r=1e9;
    while(l<=r){
        long long m = l + (r-l)/2;
        long long count = 0ll + uBound(a,m) + uBound(b,m);
        
        if(count <= medIndex) l = m+1;
        else med2 = min(med2,m), r=m-1;
    }
    
    ans = (0.00+med1+med2)/2.0;
    
    return ans;    
}
