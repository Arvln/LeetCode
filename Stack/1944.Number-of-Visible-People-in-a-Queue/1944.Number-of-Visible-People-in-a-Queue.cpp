class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ret(n, 0);
        stack<int>Stack;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty()&&heights[Stack.top()]<=heights[i])
            {
                ret[Stack.top()]++;
                Stack.pop();
            }
            
            if (!Stack.empty()) ret[Stack.top()]++;
            Stack.push(i);
        }
        return ret;
    }
};