class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>count(n, vector<int>(26, 0));

        for (int i=0; i<n; i++)
            for (char c : words[i])
                count[i][c-'a']++;
        
        vector<string>ret;
        for (char c='a'; c<='z'; c++)
        {
            int minCount=INT_MAX;
            for (int i=0; i<n; i++)
                minCount=min(minCount, count[i][c-'a']);
            for (int i=minCount; i>0; i--)
                ret.push_back(string(1, c));
        }
        return ret;
    }
};