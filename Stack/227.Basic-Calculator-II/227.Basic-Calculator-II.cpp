class Solution {
public:
    int calculate(string s) {
        string S;
        for (char c : s)
            if (c!=' ') S.push_back(c);
        S.push_back('#');
        s=S;

        char sign='+';
        string cur;
        vector<int>nums;
        for (char c : s)
            if (isdigit(c)) cur.push_back(c);
            else
            {
                int num=stoi(cur);

                if (sign=='+') nums.push_back(num);
                else if (sign=='-') nums.push_back(-num);
                else if (sign=='*') nums.back()*=num;
                else nums.back()/=num;

                sign=c;
                cur="";
            }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};