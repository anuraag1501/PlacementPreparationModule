#include<queue>
class Stack {
    queue<int> q1,q2;
   public:
    Stack() {
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.size()==0;
    }

    void push(int element) {
        q1.push(element);
    }

    int pop() {
        if(q1.empty()) return -1;
        while(q1.size()>1) q2.push(q1.front()), q1.pop();
        
        swap(q1,q2);
        int ele = q2.front();
        q2.pop();
        return ele;
    }
    int top() {
        if(q1.empty()) return -1;
        while(q1.size()>1) q2.push(q1.front()), q1.pop();
        
        swap(q1,q2);
        int elem = q2.front();
        q1.push(elem);
       q2.pop();
        return elem;
    }
};