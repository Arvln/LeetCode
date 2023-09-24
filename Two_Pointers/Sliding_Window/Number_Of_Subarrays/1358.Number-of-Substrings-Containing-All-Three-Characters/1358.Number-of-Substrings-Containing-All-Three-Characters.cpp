class Solution {
public:
    int numberOfSubstrings(string s) {
        return at_most_k(s, 3)-at_most_k(s, 2);
    }
    int at_most_k(string s, int k)
    {
        int left=0, right=0, ret=0;
        vector<int> records(3, 0);
        while (right<s.size())
        {
            if(records[s[right]-'a']==0) k-=1;
            records[s[right]-'a']+=1;
            right++;

            while (left<right&&k<0)
            {
                if(records[s[left]-'a']==1) k+=1;
                records[s[left]-'a']-=1;
                left++;
            }
            ret+=right-left;
        }
        return ret;
    }
};