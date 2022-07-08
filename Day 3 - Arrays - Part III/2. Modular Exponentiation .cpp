	int modularExponentiation(int x, int n, int p) {
    long long res = 1,a = x;
    a%=p;
    while(n>0){
        if(n%2)res = (a*res)%p;
        a = (a*a)%p;
        n/=2;
    }
    return res;
}