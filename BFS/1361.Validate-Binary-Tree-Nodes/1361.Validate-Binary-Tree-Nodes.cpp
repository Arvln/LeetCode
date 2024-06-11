class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>>nexts(n);
        vector<int>indegree(n, 0);
        for (int i=0; i<n; i++)
        {
            if (leftChild[i]!=-1)
            {
                nexts[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
            if (rightChild[i]!=-1)
            {
                nexts[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }

        queue<int>q;
        for (int i=0; i<n; i++)
            if (indegree[i]==0) q.push(i);
            else if (indegree[i]>1) return false;
        if (q.size()>1) return false;

        while (!q.empty())
        {
            int cur=q.front();
            q.pop();
            n--;

            for (int next : nexts[cur])
            {
                indegree[next]--;
                if (indegree[next]==0) q.push(next);
            }
        }
        return n==0;
    }
};