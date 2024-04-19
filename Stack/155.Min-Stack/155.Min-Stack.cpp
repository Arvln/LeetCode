class MinStack {
    vector<pair<int, int>>Stack; // {val, min val}
    int minVal=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        Stack.push_back({val, minVal});
        minVal=min(minVal, val);
    }
    
    void pop() {
        if (top()==minVal) minVal=Stack.back().second;
        Stack.pop_back();
    }
    
    int top() {
        return Stack.back().first;
    }
    
    int getMin() {
        return minVal;
    }
};