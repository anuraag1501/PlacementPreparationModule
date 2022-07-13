class Queue {
    vector<int> q;
    int rear, frnt, n;
public:
    Queue() {
        frnt = rear = 0;
        q.resize(50001);
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return frnt == rear;
    }

    void enqueue(int data) {
            q[rear++] = data;
    }

    int dequeue() {
        if(frnt == rear) return -1;
        return q[frnt++];
    }

    int front() {
        if(frnt == rear) return -1;
        return q[frnt];
    }
};