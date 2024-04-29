class Solution {
    vector<int>visited;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        visited=vector<int>(n, 0);
        dfs(rooms, 0);
        for (int i=0; i<n; i++)
            if (visited[i]==0) return false;
        return true;
    }
    void dfs(vector<vector<int>> &rooms, int id)
    {
        if (visited[id]==1) return;
        visited[id]=1;

        for (int key : rooms[id])
            if (visited[key]==0) dfs(rooms, key);
    }
};