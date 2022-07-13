bool isValidParenthesis(string expression){
    stack<char> st;
    
    for(auto ch : expression){
        if(ch=='{' || ch=='(' || ch=='['){
            st.push(ch);
            continue;
        }
        else if(st.empty()) return false;
        else if(ch==')'){
            if(st.top() != '(')
                return false;
        }
        else if(((int)(ch-st.top())) != 2) return false;
        st.pop();
    }
    return st.empty();
}