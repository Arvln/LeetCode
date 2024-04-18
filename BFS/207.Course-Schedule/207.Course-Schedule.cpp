class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>nexts(numCourses);
        vector<int>indegree(numCourses, 0);
        for (auto &req : prerequisites)
        {
            int a=req[0], b=req[1];
            nexts[b].push_back(a);
            indegree[a]++;
        }

        queue<int>q;
        for (int i=0; i<numCourses; i++)
            if (indegree[i]==0) q.push(i);
        
        int count=0;
        while (!q.empty())
        {
            int cur=q.front();
            q.pop();
            count++;

            for (int next : nexts[cur])
            {
                indegree[next]--;
                if (indegree[next]==0) q.push(next);
            }
        }
        return count==numCourses;
    }
};