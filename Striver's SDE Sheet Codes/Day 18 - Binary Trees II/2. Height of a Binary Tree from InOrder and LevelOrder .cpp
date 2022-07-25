#include<bits/stdc++.h>
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N) {
    if(N <= 1) return 0;
    
    int h = 0,li=0;
    queue<vector<int>> q;
    
    map<int,set<int>> mp;
    for(int i = 0; i < N; i++)
        mp[inorder[i]].insert(i);
    
    q.push({0,N-1,0,0});
    while(!q.empty()){
        int ii = q.front()[0];
        int in = q.front()[1];
        int ht = q.front()[2];
        q.pop();

        h = max(h,ht);
        auto rootIndexIT = mp[levelOrder[li]].lower_bound(ii);
        if(rootIndexIT == mp[levelOrder[li]].end())
            continue;
        
        li++;
        int root = *rootIndexIT;
        if(root > in) continue;
        
        if(ii < root)
            q.push({ii,root-1,ht+1});
        if(root < in)
            q.push({root+1,in,ht+1});
    }
    return h;
}