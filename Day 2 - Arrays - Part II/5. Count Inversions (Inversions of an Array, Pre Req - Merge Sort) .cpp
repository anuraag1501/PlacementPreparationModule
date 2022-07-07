long long ans;

void merge(long long *arr, int l, int m, int r){
    long long left[m-l+2];
    long long right[r-m+1];
    left[m-l+1] = right[r-m] = INT_MAX;
    
    for(int i=0; i<=m-l; i++){
        left[i] = arr[l+i];
    }
    for(int i=0; i<r-m; i++)
        right[i] = arr[m+i+1];
    int k=l,i=0,j=0;
    while(k <= r){
        if(right[j] < left[i]){
            arr[k] = right[j];
            ans += (m-l+1) - i;
            k++,j++;
        }
        else{
            arr[k] = left[i];
            i++,k++;
        }
    }
    while(i<=m-l) arr[k++] = left[i++];
    while(j<r-m)  arr[k++] = right[j++];
}

void mergeSort(long long *arr, int i, int j){
    if(i<j){
        int mid = i + (j-i)/2;
        mergeSort(arr,i,mid);
        mergeSort(arr,mid+1,j);
        merge(arr,i,mid,j);
    }
}

long long getInversions(long long *arr, int n){
    ans = 0;
    mergeSort(arr,0,n-1);
    return ans;
}