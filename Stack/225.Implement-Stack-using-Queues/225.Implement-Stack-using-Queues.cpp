class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int size=q.size(); size>1; size--, q.pop())
            q.push(q.front());
    }
    
    int pop() {
        int ret=q.front();
        q.pop();
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};