class Solution {
    vector<string>ret;
public:
    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, "", 0, 0);
        return ret;
    }
    void dfs(string& num, int& target, int pos, string path, long prev, long last)
    {
        if (pos==num.size()&&prev+last==target)
            ret.push_back(path);

        for (int i=pos+1; i<=num.size(); i++)
        {
            string str=num.substr(pos, i-pos);
            if (str.size()>1 && str[0]=='0') continue;
            long val=stol(str);

            if (path.empty())
                dfs(num, target, i, str, prev, val);
            else
            {
                dfs(num, target, i, path+'+'+str, prev+last, val);
                dfs(num, target, i, path+'-'+str, prev+last, -val);
                dfs(num, target, i, path+'*'+str, prev, last*val);
            }
        }
    }
};