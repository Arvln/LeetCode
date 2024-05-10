class NestedIterator {
    stack<NestedInteger>Stack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        while (!nestedList.empty())
        {
            Stack.push(nestedList.back());
            nestedList.pop_back();
        }
    }
    
    int next() {
        int num=Stack.top().getInteger();
        Stack.pop();
        return num;
    }
    
    bool hasNext() {
        while (!Stack.empty()&&!Stack.top().isInteger())
        {
            vector<NestedInteger>list=Stack.top().getList();
            Stack.pop();
            
            while (!list.empty())
            {
                Stack.push(list.back());
                list.pop_back();
            }
        }
        return !Stack.empty();
    }
};