class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>len(n, 1);
        vector<int>count(n, 1);

        for (int i=0; i<n; i++)
            for (int j=0; j<i; j++)
            {
                if (nums[j]>=nums[i]) continue;
                else if (len[j]+1>len[i])
                {
                    len[i]=len[j]+1;
                    count[i]=count[j];
                }
                else if (len[j]+1==len[i]) count[i]+=count[j];
            }
        
        int maxLen=0, ret=0;
        for (int i=0; i<n; i++)
            if (maxLen<len[i])
            {
                maxLen=len[i];
                ret=count[i];
            }
            else if (maxLen==len[i]) ret+=count[i];
        return ret;
    }
};