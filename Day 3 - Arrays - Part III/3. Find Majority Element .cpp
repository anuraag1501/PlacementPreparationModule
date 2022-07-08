int findMajorityElement(int arr[], int n) {
    sort(arr,arr+n);
    int count = 1;
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]) count++;
        else count = 1;
        if(count > n/2) return arr[i];
    }
    return count > n/2 ? arr[n-1] : -1;
}