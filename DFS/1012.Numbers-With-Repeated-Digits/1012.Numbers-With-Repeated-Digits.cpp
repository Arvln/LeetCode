class Solution {
    int ret=0;
public:
    int numDupDigitsAtMostN(int n) {
        string s=to_string(n);
        for (int len=1; len<=s.size()-1; len++)
            ret+=A(10, len)-A(9, len-1);
        
        vector<int> visited(10, 0);
        dfs(s, 0, visited);
        return n-ret;
    }
    void dfs(string& s, int i, vector<int>& visited)
    {
        int n=s.size();
        if (i>=n)
        {
            ret+=1;
            return;
        }

        for (int k=0; k<=9; k++)
        {
            if (i==0&&k==0) continue;
            if (visited[k]) continue;

            if (k<s[i]-'0')
                ret+=A(10-(i+1), n-(i+1));
            else if (k==s[i]-'0')
            {
                visited[k]=1;
                dfs(s, i+1, visited);
                visited[k]=0;
            }
        }
    }
    int A(int m, int n)
    {
        int ret=1;
        for (int i=0; i<n; i++)
            ret*=m-i;
        return ret;
    }
};