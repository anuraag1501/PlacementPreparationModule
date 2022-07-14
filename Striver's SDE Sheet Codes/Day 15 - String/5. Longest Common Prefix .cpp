string longestCommonPrefix(vector<string> &arr, int n) {
    int l=arr[0].length();
    for(int i=1; i<arr.size(); i++){
        if(arr[i].length() < l) l = arr[i].length();
        for(int j=0; j<l; j++){
            if(arr[i][j] != arr[0][j]){
                l = j;
                break;
            }
        }
    }
    return arr[0].substr(0,l);
}