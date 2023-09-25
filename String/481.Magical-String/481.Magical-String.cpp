class Solution {
public:
    int magicalString(int n) {
        string s="122";
        for (int i=2; s.size()<n; i++)
        {
            char last=('3'-s.back())+'0';
            if (s[i]=='1')
                s.push_back(last);
            else
            {
                s.push_back(last);
                s.push_back(last);
            }
        }
        int ret=0;
        for (int i=0; i<n; i++)
            if (s[i]=='1')
                ret+=1;
        return ret;
    }
};