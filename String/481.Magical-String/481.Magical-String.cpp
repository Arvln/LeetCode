class Solution {
public:
    int magicalString(int n) {
        string s="122";
        for (int i=2; s.size()<n; i++)
        {
            if (s[i]=='1')
                s.push_back('0'+('3'-s.back()));
            else
            {
                char last=s.back();
                s.push_back('0'+('3'-last));
                s.push_back('0'+('3'-last));
            }
        }
        int ret=0;
        for (int i=0; i<n; i++)
            if (s[i]=='1')
                ret+=1;
        return ret;
    }
};