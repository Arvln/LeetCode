# 133.Clone-Graph

深拷貝一幅圖等同於遍歷圖，採用 DFS 程式碼較為簡潔易懂，圖是類似一棵多叉樹的結構，因此遍歷方式跟遍歷樹幾乎一樣

```
void dfs(Node* node) {
    if (node==NULL) return;

    for (Node* cur : node->neighbors)
      dfs(cur);
}
```

唯一需要注意的是，樹是有向無環圖，遞歸遍歷不會走回頭路，有環圖遍歷可能走回頭路需要加上 visited 避免走回頭路

```
if (visited.find(node)!=visited.end())
  return visited[node];
```
