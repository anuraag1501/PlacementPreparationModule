int revPair;

void merge(vector<int>& arr, int l, int m, int r){
    int ls = m-l+1;
    int rs = r-m;
    
    vector<int> left(ls), right(rs);
    
    for(int i=0; i<ls; i++) left[i] = arr[i+l];
    for(int i=0; i<rs; i++) right[i] = arr[i+m+1];
    
    int i = 0, j = 0, k = l;
    
    while(i<ls && j < rs){
        if(left[i] > right[j]){
            int s = upper_bound(left.begin()+i, left.end(), 2*right[j])
                        - left.begin();
            revPair += ls - s;
            arr[k] = right[j];
            k++; j++;
        }else{
            arr[k] = left[i];
            i++;k++;
        }
    }
    while(i<ls) arr[k++] = left[i++];
    while(j<rs) arr[k++] = right[j++];
}


void modifiedMerge(vector<int>&arr, int i, int j){
    if(i<j){
        int mid = i + (j-i)/2;
        modifiedMerge(arr,i,mid);
        modifiedMerge(arr,mid+1,j);
        merge(arr, i, mid, j);
    }
}

int reversePairs(vector<int> &arr, int n){
    revPair = 0;
    modifiedMerge(arr,0,n-1);
    return revPair;
}