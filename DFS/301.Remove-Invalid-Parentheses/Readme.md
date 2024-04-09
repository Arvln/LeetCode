# 301.Remove-Invalid-Parentheses

求所有最大可能長度的有效字串，要求返回所有結果需要回溯，回溯會把所有字串都構造出來，終止條件需要知道最大有效字串的長度，思路跟 #921 差不多，先算最少要移除的數量再推出最大可能長度maxLen。

```
int left=0, removed=0;
for (char c : s)
  if (c=='(') left++;
  else if (c==')')
  {
    left--;
    if (left<0)
    {
      left=0;
      removed++;
    }
  }

removed+=left;
maxLen=s.size()-removed;
```

題目轉成要求長度為maxLen的所有有效字串，先定義DFS函數，回溯需要當前元素索引跟左右括號數量。每個小寫英文字母必選，左右括號可以取或不取，邊界條件有兩個，一個是當左括號數小於右括號不必繼續往下搜，當左右括號數相等且長度為maxLen即可更新答案。

```
void dfs(int i, int left, int right);
```

回溯過程會有重複選取的情況，假設有連續4個左括號，要取其中兩個左括號會有高達6種可能回溯路徑。要解決重複選取的問題可以參考組合或排列的去重的剪枝技巧，假設前一個取的括號跟當前括號一樣，那就必取當前括號，最後符合條件只有取最後兩個括號的情況，就是XXOO。

```
O -> 取
X -> 不取
(((( ))

OOXX -> OOOO
OXOX -> OOOO
OXXO -> OOOO
XOXO -> XOOO
XOOX -> XOOO
XXOO -> XXOO -> unique
```

當前一個取的括號跟當前括號不相等才可以不取當前括號。

```
if (path.empty()||path.back()!=s[i])
  dfs(i+1, left, right);
```
