#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size()-1;
    
    vector<vector<int>> ans;
    
    while(i<j){
        if(arr[i] + arr[j] == s){
            do{
                int si = i, sj = j;
                ans.push_back({arr[i],arr[sj--]});
                while(sj>i && arr[sj+1] == arr[sj])
                    ans.push_back({arr[i],arr[sj--]});
                i++;
            }while(i < j && arr[i] == arr[i-1]);
        }
        else if(arr[i] + arr[j] > s) j--;
        else i++;
    }
    return ans;
}