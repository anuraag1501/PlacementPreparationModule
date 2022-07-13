#include<algorithm>
void sortStack(stack<int> &st){
	if(st.size() < 2) return;

    int t = st.top();
    st.pop();
    if(st.top() > t){
        int t1 = st.top();
        st.pop();
        st.push(t);
        swap(t,t1);
    }
    sortStack(st);

    if(st.top() <= t){
        st.push(t);
        return;
    }

    int t2 = st.top();
    st.pop();
    st.push(t);
    sortStack(st);
    st.push(t2);
}