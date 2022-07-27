#include<queue>
class Kthlargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    Kthlargest(int k, vector<int> &arr) {
        this->k = k;
        for(auto &x : arr){
            pq.push(x);
            if(pq.size() > k)
                pq.pop();
        }
    }

    void add(int num) {
        pq.push(num);
        if(pq.size() > k)
            pq.pop();
    }

    int getKthLargest() {
        return pq.top();
    }
};