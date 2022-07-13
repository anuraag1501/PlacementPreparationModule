#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int> sm(n,-1);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            sm[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return sm;
}