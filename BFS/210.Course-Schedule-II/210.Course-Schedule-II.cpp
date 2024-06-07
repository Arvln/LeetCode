class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>nexts(numCourses);
        vector<int>indegree(numCourses, 0);
        for (auto &prerequisite : prerequisites)
        {
            int a=prerequisite[0], b=prerequisite[1];
            nexts[b].push_back(a);
            indegree[a]++;
        }

        queue<int>q;
        for (int i=0; i<numCourses; i++)
            if (indegree[i]==0) q.push(i);
        
        vector<int>ret;
        while (!q.empty())
        {
            int cur=q.front();
            q.pop();
            ret.push_back(cur);

            for (int next : nexts[cur])
            {
                indegree[next]--;
                if (indegree[next]==0) q.push(next);
            }
        }

        if (ret.size()==numCourses) return ret;
        else return {};
    }
};