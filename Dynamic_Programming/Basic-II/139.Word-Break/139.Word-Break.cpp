class Solution {
    class Node {
    public:
        Node *next[26];
        bool isEnd;
    };
    Node *root;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root=new Node();
        for (string &word : wordDict)
        {
            Node *cur=root;
            for (char c : word)
            {
                if (cur->next[c-'a']==NULL) cur->next[c-'a']=new Node();
                cur=cur->next[c-'a'];
            }
            cur->isEnd=true;
        }

        int n=s.size();
        s.push_back('#');
        reverse(s.begin(), s.end());
        vector<bool>dp(n+1, false);
        dp[0]=true;

        for (int i=1; i<=n; i++)
        {
            Node *temp=root;
            for (int j=i; j>=1&&temp!=NULL; j--)
            {
                temp=temp->next[s[j]-'a'];
                if (dp[j-1]&&temp!=NULL&&temp->isEnd) dp[i]=true;
            }
        }
        return dp[n];
    }
};