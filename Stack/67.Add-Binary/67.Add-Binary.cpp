class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        for (int k=0; !a.empty()||!b.empty()||k>0; k/=2)
        {
            if (!a.empty())
            {
                k+=a.back()-'0';
                a.pop_back();
            }
            if (!b.empty())
            {
                k+=b.back()-'0';
                b.pop_back();
            }
            ret.push_back((k%2)+'0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};