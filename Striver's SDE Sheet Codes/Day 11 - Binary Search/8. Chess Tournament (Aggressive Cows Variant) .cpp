int noOfPersons(vector<int>& p, int gap){
    int prsn = 1, prev = p[0];
    
    for(int i=1; i<p.size(); i++)
        if(prev+gap <= p[i]) prev = p[i],prsn++;
    return prsn;
}
int chessTournament(vector<int>& positions , int n ,  int c){
    sort(positions.begin(), positions.end());
    int 
        l = 1,
        r = positions.back(),
        ans = 1;
    
    while(l <= r){
        int mid = l + (r-l)/2;
        
        if(noOfPersons(positions,mid) >= c) ans = max(ans,mid), l = mid+1;
        else r = mid-1;
    }
    return ans;
}