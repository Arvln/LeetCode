class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int n=heights.size();
        stack<int>Stack;

        int ret=0;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty()&&heights[Stack.top()]>heights[i])
            {
                int height=heights[Stack.top()];
                Stack.pop();

                int weight=i-Stack.top()-1;
                ret=max(ret, height*weight);
            }
            Stack.push(i);
        }

        return ret;
    }
};