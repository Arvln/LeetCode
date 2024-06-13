class Solution {
    static bool cmp(string &a, string &b)
    {
        return a.size()<b.size();
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int>Map; // word->idx
        for (int i=0; i<words.size(); i++)
            Map[words[i]]=i;
        
        sort(words.begin(), words.end(), cmp);
        unordered_set<string>Set;
        vector<vector<int>>ret;
        for (string &word : words)
        {
            for (int i=0; i<=word.size(); i++)
            {
                if (isPalindrome(word, 0, i-1))
                {
                    string back=word.substr(i);
                    reverse(back.begin(), back.end());
                    if (Set.find(back)!=Set.end()) ret.push_back({Map[back], Map[word]});
                }
                if (isPalindrome(word, i, word.size()-1))
                {
                    string front=word.substr(0, i);
                    reverse(front.begin(), front.end());
                    if (Set.find(front)!=Set.end()) ret.push_back({Map[word], Map[front]});
                }
            }
            Set.insert(word);
        }
        return ret;
    }
    bool isPalindrome(string &s, int i, int j)
    {
        while (i<j)
        {
            if (s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};