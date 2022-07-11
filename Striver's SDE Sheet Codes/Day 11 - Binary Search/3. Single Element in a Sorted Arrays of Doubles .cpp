int uniqueElement(vector<int>& arr,int n){
    if(n==1) return arr[0];
    int l=0, r=n-1;
    while(l < r){
        int mid = l + (r-l)/2;
        
        if(mid%2){
            if(arr[mid]==arr[mid-1]) l = mid+1;
            else r = mid;
        }else{
            if(arr[mid]==arr[mid+1]) l = mid+2;
            else r = mid;
        }
    }
    return arr[l];
}
