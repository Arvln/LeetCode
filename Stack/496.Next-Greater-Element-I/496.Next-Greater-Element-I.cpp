class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>Map; // val->next greater
        for (int num : nums2)
            Map[num]=-1;
        
        stack<int>Stack;
        for (int num : nums2)
        {
            while (!Stack.empty()&&Stack.top()<num)
            {
                Map[Stack.top()]=num;
                Stack.pop();
            }
            Stack.push(num);
        }

        vector<int>ret;
        for (int num : nums1)
            ret.push_back(Map[num]);
        return ret;
    }
};