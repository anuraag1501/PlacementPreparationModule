#include<stack>
class Queue {
    stack<int> st1, st2;

    public:
    Queue() {
    }

    void enQueue(int val) {
        st1.push(val);
    }
    void fill(stack<int>& st1, stack<int>& st2){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }
    int deQueue() {
        if(st1.empty() && st2.empty()) return -1;
        if(st2.empty()) fill(st1,st2);
        int elem = st2.top();
        st2.pop();
        return elem;
    }

    int peek() {
        if(st1.empty() && st2.empty()) return -1;
        if(st2.empty()) fill(st1,st2);
        return st2.top();
    }

    bool isEmpty() {
        return st1.empty() && st2.empty();
    }
};