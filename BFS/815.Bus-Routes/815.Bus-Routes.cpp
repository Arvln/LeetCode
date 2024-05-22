class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n=routes.size();
        unordered_map<int, vector<int>>stopToBus;
        for (int i=0; i<n; i++)
            for (int stop : routes[i])
                stopToBus[stop].push_back(i);
        
        queue<int>q;
        vector<int>visitedBus(n, 0);
        unordered_set<int>visitedStop;
        q.push(source);
        visitedStop.insert(source);
        int ret=0;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                int curStop=q.front();
                q.pop();

                if (curStop==target) return ret;

                for (int bus : stopToBus[curStop])
                {
                    if (visitedBus[bus]==1) continue;
                    visitedBus[bus]=1;

                    for (int stop : routes[bus])
                    {
                        if (visitedStop.find(stop)!=visitedStop.end()) continue;
                        q.push(stop);
                        visitedStop.insert(stop);
                    }
                }
            }
            ret++;
        }
        return -1;
    }
};