#include<algorithm>
int maximumProduct(vector<int> &arr, int n) {
    long mn = LLONG_MAX, mx = LLONG_MIN, currMin, currMax;
    
    currMin = currMax = 1;
    
    for(long x : arr){
        long t1 = currMin*x;
        long t2 = currMax*x;
        
        currMin = min(t1,t2);
        currMax = max(t1,t2);
        
        mx = max(mx,currMax);
        mn = min(mn,currMin); 
        
        if(currMin==0) currMin = 1;
        if(currMax<=0) currMax = 1;
    }
    return mx;
}
