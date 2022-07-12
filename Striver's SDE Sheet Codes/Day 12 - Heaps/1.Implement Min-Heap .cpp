int extract(vector<int>& heap){
    int mn = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int n = heap.size(), i=0,l=1,r=2;
    while(l<n){
        int mn = i;
        if(heap[l] < heap[i]) mn = l;
        if(r<n && heap[r] < heap[mn]) mn = r;
        if(mn == i) break;
        swap(heap[i],heap[mn]);
        i = mn;
        l = 2*i+1;
        r = 2*i+2;
    }
    return mn;
}
void insert(vector<int>& heap, int x){
    heap.push_back(x);
    
    int i = heap.size()-1;
    while(i){
        int p = (i-1)/2;
        if(heap[i] >= heap[p]) break;
        swap(heap[i],heap[p]);
        i=p;            
    }
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>
            heap,
            ans;
    for(auto x : q){
        if(!x[0]) insert(heap,x[1]);
        else ans.push_back(extract(heap));
    }
    return ans;
}
