#include<bits/stdc++.h>
//UpperBound function
int uBoundIndex(vector<int>& arr, int k){
    if(arr.back() <= k) return arr.size();
    int l = 0,r=arr.size()-1;
    while(l<r){
        int mid = l + (r-l)/2;
        if(arr[mid] <= k) l = mid+1;
        else r = mid;
    }
    return l;
}
int getMedian(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size(), medPos = m*n/2;
    int l = 1, r = 1e5, ans = r;
  
    while(l<=r){
        int mid = l + (r-l) /2;
        int count = 0;
        
        for(int i=0; i<n; i++)
			//counting the number of elements smaller than or equal to mid
            count += uBoundIndex(mat[i],mid);
        
        if(count <= medPos) l = mid+1;
        else ans = min(ans,mid), r = mid-1;
    }
    return ans;
}