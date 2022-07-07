vector<int> nextPermutation(vector<int> &perm, int n){
    n--;
    while(n > 0 && perm[n] <= perm[n-1]) n--;
    sort(perm.begin()+n,perm.end());
    
    if(n)
        swap(perm[n-1],perm[upper_bound(perm.begin()+n,perm.end(),perm[n-1]) - perm.begin()]);
    
    return perm;
}