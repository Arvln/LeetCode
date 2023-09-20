class Solution {
public:
    bool isNumber(string s) {
        string t="";
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='+'||s[i]=='-')
            {
                if (i>0&&s[i-1]!='e'&&s[i-1]!='E') return false;
            }
            else if (s[i]!='e'&&s[i]!='E'&&s[i]!='.'&&!isdigit(s[i]))
                return false;
            else
                t.push_back(s[i]);
        }
        if (t.empty()||t==".") return false;

        int count_e=0, count_dot=0;
        for (int i=0; i<t.size(); i++)
        {
            if (t[i]=='e'||t[i]=='E')
            {
                if (count_e) return false;
                if (i==0||i==t.size()-1) return false;
                if (!isNumber(t.substr(0, i))) return false;
                count_e+=1;
            }
            if (t[i]=='.')
            {
                if (count_e||count_dot) return false;
                count_dot+=1;
            }
        }
        return true;
    }
};