# 417.Pacific-Atlantic-Water-Flow

要確認哪些格子雨水能同時流入海中，可以分為兩種思路

```
I. 遍歷所有格子模擬雨水流向
II. 以鄰接太平洋、大西洋格子推導可以流到海洋的格子
```

選 II.不用遍歷所有格子可能流到海中路徑，只要確認可以流進目標海域即可，把鄰接海洋單元格當作 DFS 起點

```
for (int i=0; i<m; i++)
{
    dfs(i, 0, INT_MIN, heights, pac);
    dfs(i, n-1, INT_MIN, heights, alt);
}
for (int j=0; j<n; j++)
{
    dfs(0, j, INT_MIN, heights, pac);
    dfs(m-1, j, INT_MIN, heights, alt);
}
```

從四個方向做擴散，避免越界問題，sea 向量標記是否可流到大海並起到遍歷圖時 visited 數組防止走回頭路的功能

```
void dfs(int i, int j, int height, vector<vector<int>>& heights, vector<vector<int>>& sea)
{
    if (i<0||j<0||i>=m||j>=n) return;
    if (sea[i][j]||height>heights[i][j]) return;

    sea[i][j]=1;
    dfs(i-1, j, heights[i][j], heights, sea);
    dfs(i+1, j, heights[i][j], heights, sea);
    dfs(i, j-1, heights[i][j], heights, sea);
    dfs(i, j+1, heights[i][j], heights, sea);
}
```

最後再遍歷一次所有單元格取出流入太平洋及大西洋格子更新答案
