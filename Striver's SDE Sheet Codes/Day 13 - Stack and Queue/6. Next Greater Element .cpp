#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ng(n,-1);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            ng[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ng;
}