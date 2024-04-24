class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for (char c : num)
        {
            while (!s.empty()&&s.back()>c&&k>0)
            {
                s.pop_back();
                k--;
            }
            if (s.empty()&&c=='0') continue;
            s.push_back(c);
        }
        while (!s.empty()&&k>0)
        {
            s.pop_back();
            k--;
        } 
        if (s.empty()) return "0";
        else return s;
    }
};