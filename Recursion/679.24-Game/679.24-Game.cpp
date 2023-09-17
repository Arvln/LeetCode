class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums(cards.begin(), cards.end());
        sort(nums.begin(), nums.end());
        while(next_permutation(nums.begin(), nums.end()))
        {
            unordered_set<double> dp=dfs(nums, 0, cards.size()-1);
            for (double res : dp)
                if (abs(res-24.0)<1e-10)
                    return true;
        }
        return false;
    }
    unordered_set<double> dfs(vector<double>& nums, int i, int j)
    {
        if (i==j) return {nums[i]};
        unordered_set<double>ret;
        for (int k=i; k<j; k++)
        {
           unordered_set<double> left=dfs(nums, i, k); 
           unordered_set<double> right=dfs(nums, k+1, j);

           for (double x : left)
                for (double y : right)
                {
                    ret.insert(x+y);
                    ret.insert(x-y);
                    ret.insert(x*y);
                    if (y>0)
                        ret.insert(x/y);
                } 
        }
        return ret;
    }
};