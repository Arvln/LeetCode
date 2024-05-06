class Solution {
public:
    string reverseWords(string s) {
        while (!s.empty()&&s.back()==' ')
            s.pop_back();
        reverse(s.begin(), s.end());
        while (!s.empty()&&s.back()==' ')
            s.pop_back();

        string str;
        for (char c : s)
            if (c==' '&&!str.empty()&&str.back()==' ') continue;
            else str.push_back(c);
        s=str;
        
        for (int i=0; i<s.size(); i++)
        {
            int j=i;
            while (j<s.size()&&s[j]!=' ')
                j++;
            reverse(s.begin()+i, s.begin()+j);
            i=j;
        }
        return s;
    }
};