#include<stack>
vector<int> nextSmaller(vector<int>&a, int n){
    stack<int> st;
    vector<int> ns(n,n);
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[i] < a[st.top()]){
            ns[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ns;
}
vector<int> prevSmaller(vector<int>&a, int n){
    stack<int> st;
    vector<int> ps(n,-1);
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if(!st.empty())
            ps[i] = st.top();
        st.push(i);
    }
    return ps;
}
vector<int> maxMinWindow(vector<int>& a, int n) {
    stack<int> st;
    
    vector<int> ns = nextSmaller(a,n);
    vector<int> ps = prevSmaller(a,n);

    vector<int> ans(n,-1e9);
    
    for(int i = 0; i < n;i++){
        int l = ns[i] - ps[i] - 1;
        ans[l-1] = max(ans[l-1],a[i]);
    }
    
    for(int i = n-2; i>=0; i--)
        ans[i] = max(ans[i],ans[i+1]);
    
    return ans;
}