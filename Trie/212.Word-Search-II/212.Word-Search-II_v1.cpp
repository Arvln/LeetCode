class Solution {
    class TrieNode
    {
        public:
            TrieNode* next[26];
            bool isEnd;
            TrieNode()
            {
                for (int i=0; i<26; i++)
                    next[i]=NULL;
                isEnd=false;
            }
    };
    TrieNode* root;
    int m, n;
    vector<string> ret;
    bool visited[12][12];
    vector<pair<int, int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new TrieNode();
        for (string word : words)
        {
            TrieNode* cur=root;
            for (char c : word)
            {
                if (cur->next[c-'a']==NULL)
                    cur->next[c-'a']=new TrieNode();
                cur=cur->next[c-'a'];
            }
            cur->isEnd=true;
        }

        m=board.size(), n=board[0].size();
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                string word;
                dfs(board, i, j, root, word);
            }
        return ret;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, string& word)
    {
        node=node->next[board[i][j]-'a'];
        if (node==NULL) return;

        word.push_back(board[i][j]);
        if (node->isEnd)
        {
            ret.push_back(word);
            node->isEnd=false;
        }

        visited[i][j]=true;
        for (auto [x, y] : dirs)
        {
            x=i+x, y=j+y;
            if (x<0||y<0||x>=m||y>=n) continue;
            if (visited[x][y]) continue;

            dfs(board, x, y, node, word);
        }
        visited[i][j]=false;
        word.pop_back();
    }
};