# 114.Flatten-Binary-Tree-to-Linked-List

主函數調用一下 DFS 就行，DFS 會自動在每個節點執行相同操作，寫 DFS 專注在思考單一節點要做哪些處理即可，攤平樹為鏈表，並按前序遍歷順序排列

```
cur -> left -> right
```

先把攤平右子樹並暫存節點，再攤平左子樹把結果接在右子樹上，再按要求把左子樹置為空

```
TreeNode* right=dfs(root->right);
root->right=dfs(root->left);
root->left=NULL;
```

接著遍歷一遍右子樹到底把暫存的右子樹節點接上去就行

```
TreeNode* cur=root;
while (cur->right!=NULL)
  cur=cur->right;
cur->right=right;
```
