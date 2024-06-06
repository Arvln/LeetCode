class Solution {
public:
    string decodeString(string s) {
        string num;
        string str;
        stack<int>nums;
        stack<string>strs;
        for (char c : s)
            if (isdigit(c)) num.push_back(c);
            else if (isalpha(c)) str.push_back(c);
            else if (c=='[')
            {
                nums.push(stoi(num));
                num="";
                strs.push(str);
                str="";
            }
            else
            {
                int count=nums.top()-1;
                nums.pop();
                string temp=str;
                while (count>0)
                {
                    str+=temp;
                    count--;
                }
                str=strs.top()+str;
                strs.pop();
            }
        return str;
    }
};