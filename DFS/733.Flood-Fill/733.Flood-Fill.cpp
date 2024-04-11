class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size(), n=image[0].size();
        if (image[sr][sc]!=color)
            dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
    void dfs(vector<vector<int>>&grid, int i, int j, int target, int color)
    {
        if (i<0||j<0||i>=m||j>=n) return;
        else if (grid[i][j]!=target) return;

        grid[i][j]=color;
        for (auto dir : dirs)
            dfs(grid, i+dir[0], j+dir[1], target, color);
    }
};