/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
#include<unordered_map>

graphNode* clone(graphNode* n, unordered_map<graphNode*, graphNode*>& mp){
    if(!n)
        return n;
    
    auto it = mp.find(n);
    if(it != mp.end()) return it->second;
    
    graphNode* curr = new graphNode(n->data);
    mp[n] = curr;
    
    for(auto nbr : n->neighbours){
        it = mp.find(nbr);
        if(it == mp.end())
            clone(nbr,mp);
        curr->neighbours.push_back(mp[nbr]);
    }
    return curr;
}

graphNode* cloneGraph(graphNode *node) {
    unordered_map<graphNode*,graphNode*> mp;
    
    return clone(node,mp);
}