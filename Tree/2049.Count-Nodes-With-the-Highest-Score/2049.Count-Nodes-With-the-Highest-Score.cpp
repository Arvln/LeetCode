class Solution {
    vector<vector<int>>nexts;
    int ret=0, n;
    long long maxScore=0;
public:
    int countHighestScoreNodes(vector<int>& parents) {
        n=parents.size();
        nexts.resize(n);
        for (int i=1; i<n; i++)
            nexts[parents[i]].push_back(i);   
        dfs(0);
        return ret;
    }
    int dfs(int node)
    {
        int count=1;
        long long score=1;
        for (int next : nexts[node])
        {
            int sub=dfs(next);
            count+=sub;
            score*=sub;
        }

        score*=max(n-count, 1);
        if (score>maxScore)
        {
            maxScore=score;
            ret=1;
        }
        else if (score==maxScore) ret++;
        return count;
    }
};