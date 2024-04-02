class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>Stack;
        vector<int>preSmaller(n, -1);
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty()&&heights[Stack.top()]>heights[i])
                Stack.pop();

            if (!Stack.empty()) preSmaller[i]=Stack.top();
            Stack.push(i);
        }
        while (!Stack.empty()) Stack.pop();
        vector<int>nextSmaller(n, n);
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty()&&heights[Stack.top()]>heights[i])
            {
                nextSmaller[Stack.top()]=i;
                Stack.pop();
            }
            Stack.push(i);
        }
        int ret=0;
        for (int i=0; i<n; i++)
            ret=max(ret, heights[i]*(nextSmaller[i]-preSmaller[i]-1));
        return ret;
    }
};