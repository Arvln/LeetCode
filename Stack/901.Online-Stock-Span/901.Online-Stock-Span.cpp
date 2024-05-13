class StockSpanner {
    vector<int>prices;
    stack<int>Stack;
public:
    StockSpanner() {
        Stack.push(-1);
    }
    
    int next(int price) {
        int i=prices.size();
        prices.push_back(price);

        while (Stack.top()>=0&&prices[Stack.top()]<=price)
            Stack.pop();
        int span=i-Stack.top();
        Stack.push(i);
        return span;
    }
};