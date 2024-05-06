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
  dfs(pac, i, 0, INT_MIN);
  dfs(atl, i, n-1, INT_MIN);
}
for (int j=0; j<n; j++)
{
  dfs(pac, 0, j, INT_MIN);
  dfs(atl, m-1, j, INT_MIN);
}
```

從四個方向做擴散，避免越界問題，visited 向量標記是否可流到大海並起到防止走回頭路的功能

```
void dfs(vector<vector<int>> &visited, int i, int j, int preHeight)
{
    if (i<0||j<0||i>=m||j>=n) return;
    else if (visited[i][j]==1) return;
    else if (preHeight>heights[i][j]) return;
    visited[i][j]=1;

    for (auto dir : dirs)
        dfs(visited, i+dir[0], j+dir[1], heights[i][j]);
}
```

最後再遍歷一次所有單元格取出流入太平洋及大西洋格子更新答案
