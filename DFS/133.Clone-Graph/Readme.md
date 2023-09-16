# 133.Clone-Graph

深拷貝一幅圖等同於遍歷圖，採用 DFS 程式碼較為簡潔易懂，圖就是一棵多叉樹，因此遍歷方式跟遍歷樹幾乎一樣

```
Node* dfs(Node* node) {
    if (node==NULL) return NULL;

    Node* newNode=new Node(node->val);
    for (Node* cur : node->neighbors)
        newNode->neighbors.push_back(dfs(cur));

    return newNode;
}
```

唯一需要注意的是，樹是有向無環圖，遞歸遍歷不會走回頭路，有環圖遍歷可能走回頭路需要加上 visited 避免走回頭路

```
if (visited.find(node)!=visited.end())
  return visited[node];
```
