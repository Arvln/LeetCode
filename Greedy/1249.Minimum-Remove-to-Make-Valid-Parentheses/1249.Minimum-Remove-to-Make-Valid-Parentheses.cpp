class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>Stack;
        for (int i=0; i<s.size(); i++)
            if (s[i]=='(') Stack.push(i);
            else if (s[i]==')')
            {
                if (Stack.empty()) s[i]=' ';
                else Stack.pop();
            }
        
        while (!Stack.empty())
        {
            s[Stack.top()]=' ';
            Stack.pop();
        }
        string ret;
        for (char c : s)
            if (c!=' ') ret.push_back(c);
        return ret;
    }
};