class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>Stack;
        int n=temperatures.size();
        vector<int>ret(n, 0);
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty()&&temperatures[Stack.top()]<temperatures[i])
            {
                ret[Stack.top()]=i-Stack.top();
                Stack.pop();
            }
            Stack.push(i);
        }
        return ret;
    }
};