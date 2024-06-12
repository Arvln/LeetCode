class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>>grid1, grid2;
    int m, n;
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid2.size(), n=grid2[0].size();
        this->grid1=grid1, this->grid2=grid2;
        int ret=0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (this->grid2[i][j]==1&&isSub(i, j)) ret++;
        return ret;
    }
    bool isSub(int i, int j)
    {
        if (i<0||j<0||i>=m||j>=n) return true;
        else if (grid2[i][j]!=1) return true;
        else if (grid1[i][j]!=1) return false;
        grid2[i][j]=2;

        bool ret=true;
        for (auto dir : dirs)
            if (!isSub(i+dir[0], j+dir[1])) ret=false;
        return ret;
    }
};