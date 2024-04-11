class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>ret(m, vector<int>(n));
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                ret[(i+(j+k)/n)%m][(j+k)%n]=grid[i][j];
        return ret;
    }
};