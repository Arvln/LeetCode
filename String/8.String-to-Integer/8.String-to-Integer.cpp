class Solution {
public:
    int myAtoi(string s) {
        string S=s;
        s="";

        for (char c : S)
            if (isalpha(c)||c=='.') break;
            else if (!isdigit(c)&&!s.empty()) break;
            else if (c=='+'||c=='-'||isdigit(c)) s.push_back(c);

        bool isPos=true;
        long long ret=0;
        for (char c : s)
            if (c=='+'||c=='-') isPos=c=='+';
            else if (ret<INT_MAX) ret=ret*10+(c-'0');
        
        if (isPos)
        {
            ret=min(ret, (long long)INT_MAX);
            return ret;
        }
        else
        {
            ret=max(-ret, (long long)INT_MIN);
            return ret;
        }
    }
};