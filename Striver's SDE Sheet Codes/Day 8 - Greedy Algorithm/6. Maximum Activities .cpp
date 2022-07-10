#include<bits/stdc++.h>

void write(vector<int>& st, vector<int>&fin,vector<vector<int>>& act, int l, int m, int r){
    
    int i=l, j=m+1, k=l;
    while(i <= m && j <= r){
        if(fin[i] < fin[j]){
            act[k] = {fin[i],st[i]};
            i++,k++;
        }
        else{
            act[k] = {fin[j],st[j]};
            j++,k++;
        }
    }
    while(i <= m) {act[k] = {fin[i],st[i]}; i++,k++;}
    while(j <= r) {act[k] = {fin[j],st[j]}; j++,k++;}
    
    for(; l<=r; l++) fin[l] = act[l][0], st[l] = act[l][1];
}

void copy(vector<int>& st,vector<int>&fin,vector<vector<int>>&act,int i,int j){
    if(i < j){
        int m = i + (j-i)/2;
        copy(st,fin,act,i,m);
        copy(st,fin,act,m+1,j);
        write(st,fin,act,i,m,j);
    }
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<vector<int>> act(n,vector<int>(2));
    
    copy(start,finish,act,0,n-1);

    int ans = 0, end = -1;
    for(int i=0; i<n; i++){
        if(act[i][1] >= end)
            ans++,end = act[i][0];
    }
    return ans;
}