void sort012(int *arr, int n){
    int i = 0, j = 0, k = n-1;
    
    while(j <= k){
        if(arr[j] == 0 && i!=j) swap(arr[i++], arr[j]);
        else if(arr[j] == 2) swap(arr[k--], arr[j]);
        else j++;
    }
}