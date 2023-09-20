# 501.Find-Mode-in-Binary-Search-Tree

在二叉搜索樹中找出所有眾數，二叉搜索樹特性是中序遍歷時所有數字有序，遍歷時值相同的數會依序被遍歷到

```
1 2 2 2 3 3 3 ..
```

按此特性，可以一個變數存前一個節點的值跟當前節點做比較，再設定兩個計數器分別紀錄當前值出現次數跟出現次數最大值來更新結果

```
int prev, count, max_count;
```

在中序遍歷時比較計數器並更新前一個節點值，當前值出現次數大於最大值時，更新最大值並重新累計結果，當前值出現次數等於最大值時，新增當前值到結果集合中

```
dfs(root->left);
if (prev==root->val)
  count+=1;
else
  count=1;
prev=root->val;

if (count>max_count)
{
  max_count=count;
  ret={root->val};
}
else if (count==max_count)
  ret.push_back(root->val);
dfs(root->right);
```
