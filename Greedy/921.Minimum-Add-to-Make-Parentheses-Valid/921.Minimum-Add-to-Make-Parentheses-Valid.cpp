class Solution {
public:
    int minAddToMakeValid(string s) {
        int left=0, right=0;
        for (char c : s)
            if (c=='(') left++;
            else
            {
                left--;
                if (left<0)
                {
                    left=0;
                    right++;
                }
            }
        return left+right;
    }
};