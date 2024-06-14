class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>Stack({-1});
        int ret=0;
        for (int i=0; i<s.size(); i++)
            if (s[i]==')'&&Stack.top()!=-1&&s[Stack.top()]=='(')
            {
                Stack.pop();
                ret=max(ret, i-Stack.top());
            }
            else Stack.push(i);
        return ret;
    }
};