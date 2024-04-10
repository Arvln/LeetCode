# 1315.Sum-of-Nodes-with-Even-Valued-Grandparent

要判斷當前節點的爺爺節點是不是偶數，可以在前序遍歷做判斷，上層節點的資訊從參數裡面拿，可以先定義DFS函數。

```
void dfs(TreeNode *root, TreeNode *grandpa, TreeNode *parent);
```

每個節點只需確認爺爺節點是不是偶數，在遞歸時把當前節點爸爸升格當爺爺、當前節點升格當爸。
