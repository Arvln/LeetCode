class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_set<string>wordSet(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>>nexts;
        for (string word : wordSet)
        {
            string temp=word;
            for (int i=0; i<word.size(); i++)
                for (char c='a'; c<='z'; c++)
                {
                    if (c==word[i]) continue;

                    temp[i]=c;
                    if (wordSet.find(temp)!=wordSet.end())
                        nexts[word].push_back(temp);
                    temp[i]=word[i];
                }
        }

        queue<string>q;
        unordered_set<string>visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int ret=1;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                string cur=q.front();
                q.pop();

                if (cur==endWord) return ret;

                for (string &next : nexts[cur])
                {
                    if (visited.find(next)!=visited.end()) continue;
                    q.push(next);
                    visited.insert(next);
                }
            }
            ret++;
        }
        return 0;
    }
};