#include<queue>
void findMedian(int *arr, int n){
    if(n==0) return void(cout << "\n");
    
    priority_queue<int> sml;
    priority_queue<int,vector<int>,greater<int>> lrg;
    cout << arr[0] << ' ';
    sml.push(arr[0]);
    
    for(int i=1; i<n; i++){
        if(lrg.size() < sml.size()) lrg.push(arr[i]);
        else sml.push(arr[i]);
        while(sml.top() > lrg.top()){
            int s = sml.top();
            int l = lrg.top();
            sml.pop(), lrg.pop();
            sml.push(l);
            lrg.push(s);
        }
        if(sml.size() == lrg.size()) cout << (sml.top()+lrg.top())/2 << ' ';
        else cout << (sml.size() > lrg.size() ? sml.top() : lrg.top()) << ' ';
    }
    cout << '\n';
}