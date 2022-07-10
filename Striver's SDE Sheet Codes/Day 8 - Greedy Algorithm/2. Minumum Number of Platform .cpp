int calculateMinPatforms(int at[], int dt[], int n) {
    vector<int> a(2360), b(2360);
    
    for(int i=0; i < n; i++){
        a[at[i]]++;
        b[dt[i]]++;
    }
    int curr = 0, mx = 0;
    for(int i=0; i < 2360; i++){
        curr += a[i];
        mx = max(mx,curr);
        curr -= b[i];
    }
    return mx;
}