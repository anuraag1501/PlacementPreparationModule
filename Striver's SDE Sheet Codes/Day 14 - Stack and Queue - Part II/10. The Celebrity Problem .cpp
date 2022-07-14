#include<queue>
int findCelebrity(int n) {
    queue<int> q;
    
    //Finding possible celebrity.....since everyone knows celebrity... then 0 does too..(if he is not himself celbrity)
    for(int i=0; i<n; i++)
        if(knows(0,i))
            q.push(i);
    
    //If zero knows no one .....he could be a celebrity
    if(q.size()==0) q.push(0);
    
    //this array tells who cannot be a celebrity.....
    //if ith person cannot be a celebrity .....if someone does not know him....or ith person knows someone......we will store this information here
    vector<int> cnd(n);
    
    while(!q.empty()){
        //we are cheking if curr person can be a celebrity
        int curr = q.front();
        q.pop();
        
        //if he cannot be a celebrity......defined by cnd vector
        if(cnd[curr])continue;
        
        bool f=1;
        for(int i=0; i<n; i++){
            if(i==curr) continue;
            
            //if there exists a person i...who does not know curr....then curr cannot be celebrity
            if(!knows(i,curr)){
                f=0;
                break;
            }
            //if i knows curr....then i cannot be celebrity
            else cnd[i] = 1;
        }
        //if there is someone who does not know curr
        if(!f) continue;
        
        for(int i=0; i<n; i++){
            if(i==curr)continue;
            
            //if curr knows even one person.....then curr cannot be celebrity
            if(knows(curr,i)){
                f=0;
                break;
            }
            //here we test if ith person is celebrity or not....this will be needed in case curr person is not celebrity....and we need to explore q further
            //if curr person does not know ith person....then ith person cannot be celebrity
            else cnd[i] = 1;
        }
        //if everyone knows curr and curr knows no one
        if(f) return curr;
    }
    return -1;
}