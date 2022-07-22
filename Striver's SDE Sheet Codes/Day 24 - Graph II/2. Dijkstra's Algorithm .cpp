#include<queue>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<tuple<int,int>>> adj(vertices);
    
    for(auto &x : vec){
        adj[x[0]].push_back(make_tuple(x[1],x[2]));
        adj[x[1]].push_back(make_tuple(x[0],x[2]));
    }
    
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>
                                            > pq;
    vector<int> dist(vertices,INT_MAX);
    dist[source] = 0;
    pq.push({0,source});
    
    while(!pq.empty()){
        int node = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        for(auto &x : adj[node]){
            int totW = w + get<1>(x);
            if(totW < dist[get<0>(x)]){
                dist[get<0>(x)] = totW;
                pq.push({totW,get<0>(x)});
            }
        }
    }
    return dist;
}
