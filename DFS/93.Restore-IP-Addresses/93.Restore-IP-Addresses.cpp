class Solution {
    vector<string>ret;
    string s;
public:
    vector<string> restoreIpAddresses(string s) {
        this->s=s;
        dfs(0, "", 0);
        return ret;
    }
    void dfs(int cur, string path, int n)
    {
        if (n>4) return;
        else if (n==4&&cur==s.size())
        {
            path.pop_back();
            ret.push_back(path);
            return;
        }

        for (int i=cur; i<s.size(); i++)
        {
            if (!isValid(s, cur, i)) continue;

            dfs(i+1, path+s.substr(cur, i-cur+1)+".", n+1);
        }
    }
    bool isValid(string &s, int i, int j)
    {
        int len=j-i+1;
        if (len>3) return false;
        else if (len==1) return true;
        else if (s[i]=='0') return false;
        else if (len==2) return true;
        else
        {
            int num=0;
            while (i<=j)
            {
                num*=10;
                num+=s[i]-'0';
                i++;
            }
            return num<256;
        }
    }
};