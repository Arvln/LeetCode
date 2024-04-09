class Solution {
    static bool cmp(string &a, string &b)
    {
        return (a+b)>(b+a);
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string>strs;
        for (int num : nums)
            strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), cmp);

        string ret;
        for (string s : strs)
            ret+=s;
        
        int i=0;
        while (i<ret.size()&&ret[i]=='0')
            i++;
        
        if (i==ret.size()) return "0";
        else return ret;
    }
};