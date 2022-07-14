#include<stack>
vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector<int> ans(n,1);
    stack<int> st;
 
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && price[i] > price[st.top()]){
            ans[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ans[st.top()] = st.top()+1;
        st.pop();
    }
    return ans;
}