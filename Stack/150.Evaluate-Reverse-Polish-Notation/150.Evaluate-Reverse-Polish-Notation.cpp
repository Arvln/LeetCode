class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>Stack;
        for (string token : tokens)
            if (token=="+"||token=="-"||token=="*"||token=="/")
            {
                int num2=Stack.top();
                Stack.pop();
                int num1=Stack.top();
                Stack.pop();

                if (token=="+") Stack.push(num1+num2);
                else if (token=="-") Stack.push(num1-num2);
                else if (token=="*") Stack.push(num1*num2);
                else Stack.push(num1/num2);
            }
            else Stack.push(stoi(token));
        return Stack.top();
    }
};