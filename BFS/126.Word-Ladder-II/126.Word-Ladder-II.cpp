class Solution {
    unordered_map<string, vector<string>>prev;
    vector<vector<string>>rets;
    vector<string>path;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_set<string>Set(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>>nexts;
        for (string word : Set)
        {
            string temp=word;
            for (int i=0; i<word.size(); i++)
                for (char c='a'; c<='z'; c++)
                {
                    if (c==word[i]) continue;
                    temp[i]=c;
                    if (Set.find(temp)!=Set.end())
                        nexts[word].push_back(temp);
                    temp[i]=word[i];
                }
        }

        queue<string>q;
        unordered_set<string>visited;
        q.push(beginWord);
        visited.insert(beginWord);
        bool isEnd=false;
        while (!q.empty()&&isEnd==false)
        {
            unordered_set<string>used;
            for (int size=q.size(); size>0; size--)
            {
                string cur=q.front();
                q.pop();

                for (string next : nexts[cur])
                {
                    if (visited.find(next)!=visited.end()) continue;

                    prev[next].push_back(cur);
                    used.insert(next);
                    if (next==endWord) isEnd=true;
                }
            }
            for (string node : used)
            {
                q.push(node);
                visited.insert(node);
            }
        }

        path.push_back(endWord);
        dfs(endWord, beginWord);
        return rets;
    }
    void dfs(string &cur, string &beginWord)
    {
        if (cur==beginWord)
        {
            rets.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }

        for (string next : prev[cur])
        {
            path.push_back(next);
            dfs(next, beginWord);
            path.pop_back();
        }
    }
};