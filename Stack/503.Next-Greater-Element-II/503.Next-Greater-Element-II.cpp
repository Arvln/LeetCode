class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for (int i=0; i<n; i++)
            nums.push_back(nums[i]);
        
        stack<int>Stack;
        vector<int>nextGreater(n, -1);
        for (int i=0; i<nums.size(); i++)
        {
            while (!Stack.empty()&&nums[Stack.top()]<nums[i])
            {
                if (Stack.top()<n) nextGreater[Stack.top()]=nums[i];
                Stack.pop();
            }
            Stack.push(i);
        }
        return nextGreater;
    }
};