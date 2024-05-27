class Solution {
public:
    int calculate(string s) {
        string S;
        for (char c : s)
            if (c!=' ') S.push_back(c);
        s=S;

        stack<string>Stack;
        string cur;
        for (char c : s)
            if (c=='(')
            {
                Stack.push(cur);
                cur="";
            }
            else if (c==')')
            {
                cur=Stack.top()+to_string(parse(cur));
                Stack.pop();
            }
            else cur.push_back(c);
        return parse(cur);
    }
    int parse(string &s)
    {
        int ret=0, sign=1;
        for (int i=0; i<s.size(); i++)
            if (isdigit(s[i]))
            {
                int num=0;
                while (i<s.size()&&isdigit(s[i]))
                {
                    num=num*10+(s[i]-'0');
                    i++;
                }
                ret+=sign*num;
                i--;
            }
            else
            {
                sign=1;
                while (i<s.size()&&!isdigit(s[i]))
                {
                    sign*=s[i]=='+'?1:-1;
                    i++;
                }
                i--;
            }
        return ret;
    }
};