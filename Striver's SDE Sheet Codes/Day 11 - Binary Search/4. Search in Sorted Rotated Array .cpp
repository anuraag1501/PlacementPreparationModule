int binarySearch(int* arr, int key, int l, int r){
    if(l>r || (arr[l] < arr[r] && (arr[l] > key || arr[r] < key)) )
        return -1;
    int mid = l + (r-l)/2;
    if(arr[mid] == key)
        return mid;
    
    int s1 = binarySearch(arr,key,l,mid-1);
    if(s1 != -1)
        return s1;
    return binarySearch(arr,key,mid+1,r);
}
int search(int* arr, int n, int key) {
    return binarySearch(arr,key,0,n-1);
}