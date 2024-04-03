# 1020.Number-of-Enclaves

要算飛地總面積，可以先找到與邊緣相連的陸地，用搜索算法將找到的陸地填滿，剩下的陸地就都是飛地。

```
for (int i=0; i<m; i++)
{
    dfs(i, 0, grid);
    dfs(i, n-1, grid);
}
for (int j=0; j<n; j++)
{
    dfs(0, j, grid);
    dfs(m-1, j, grid);
}
```
