#include<stack>
vector<int> nextSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,n);
    stack<int> st;
    
    for(int i=0; i<n;i++){
        while(!st.empty() && arr[i] < arr[st.top()])
            ans[st.top()] = i,st.pop();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    
    for(int i=n-1; i>=0 ; i--){
        while(!st.empty() && arr[i] < arr[st.top()])
            ans[st.top()] = i, st.pop();
        st.push(i);
    }
    return ans;
}

int largestRectangle(vector < int > & heights) {
     vector<int> nse = nextSmaller(heights);
     vector<int> pse = prevSmaller(heights);
     int maxArea = 0;
    
    for(int i=0; i<heights.size(); i++)
        maxArea = max(maxArea,heights[i] * (nse[i] - pse[i] - 1));
    return maxArea;
 }


