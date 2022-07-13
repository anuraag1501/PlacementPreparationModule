// Stack class.
class Stack {
    vector<int> st;
    int i;
    int n;
public:
    
    Stack(int capacity) {
        st.resize(capacity);
        n = capacity;
        i=0;
    }

    void push(int num) {
        if(i<n) st[i++] = num;
    }

    int pop() {
        if(i) return st[--i];
        return -1;
    }
    
    int top() {
        if(i) return st[i-1];
        return -1;
    }
    
    int isEmpty() {
        return i==0;
    }
    
    int isFull() {
        return i==n;
    }
    
};