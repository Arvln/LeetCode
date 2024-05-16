class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int start=s.size();
        for (int i=s.size()-1; i>0; i--)
            if (s[i]<s[i-1])
            {
                start=i;
                s[i]='9';
                s[i-1]--;
            }

        while (start<s.size())
        {
            s[start]='9';
            start++;
        }
        return stoi(s);
    }
};