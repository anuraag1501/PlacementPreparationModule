#include<queue>
vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    
    vector<int> medians;
    
    for(auto &x : arr){
        if(small.size() <= large.size())
            small.push(x);
        else 
            large.push(x);
        
        while(!large.empty() &&
              !small.empty() &&
              large.top() < small.top()){
            int s = small.top();
            int l = large.top();
            small.pop();
            large.pop();
            
            large.push(s);
            small.push(l);
        }
        
        if((small.size()+large.size())%2) medians.push_back(small.top());
        else medians.push_back((small.top()+large.top())/2);
    }
    return medians;
}
