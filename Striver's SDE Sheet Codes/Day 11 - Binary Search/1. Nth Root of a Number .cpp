double eps = 1e-10;
double findNthRootOfM(int n, long long m) {
    if(n==1 || m==0 || m==1) return m;
    double start = 1, end = m, mid=(start+end)/2.0;
    while(end-start > eps){
        mid = (start+end)/2.0;
        double p = 1;
        for(int i=0; i<n; i++) p *= mid;
        if(p > m) end = mid;
        else start = mid;
    }
    return mid;
}
