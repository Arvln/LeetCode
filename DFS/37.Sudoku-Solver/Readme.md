# 37.Sudoku-Solver

解數獨需要搜索每個數字格子按規則填上字符，通常 DFS 可通過直接修改全局變量更新結果或從返回值獲得結果，由於題目更新結果的方式是在前序遍歷時直接修改圖，為避免在後序遍歷時正確的修改結果被撤銷，DFS 需要一個返回值判斷選擇是否能正確解出數獨，不能解出才能執行撤銷選擇的代碼，遍歷這幅圖不會走回頭路不需要 visited

```
bool dfs(vector<vector<char>>& board, int i, int j)
```

從左往右、從上到下遍歷，遍歷到第 10 列說明成功解出數獨，遍歷到第 10 行需要往下遍歷下一列

```
if (i==9) return true;
if (j==9) return dfs(board, i+1, 0);
```

只有沒填數字格子需要試

```
if (board[i][j]!='.') return dfs(board, i, j+1);
```

每個符合規則的字符都試一下，若每個字符都試完還是解不出來，返回 false，回退到上層執行撤銷選擇代碼並嘗試下一個字符

```
for (char k='0'; k<='9'; k++)
{
  if (!isValid(board, i, j, k)) continue;

  board[i][j]=k;
  if (dfs(board, i, j))
    return true;
  board[i][j]='.';
}
return false;
```

實作檢查字符是否合規的函數，先查所有同行元素，再查所有同列元素，最後找到九宮格最左上角座標格，先算是從上到下第幾個九宮格 i/3 再乘 3 就是最左上角格子的列座標，行座標類推，最後依序遍歷九宮格內所有數字做檢查

```
bool isValid(vector<vector<char>>& board, int i, int j, char k)
{
  for (int row=0; row<9; row++)
    if (board[row][j]==k)
      return false;
  for (int col=0; col<9; col++)
    if (board[i][col]==k)
      return false;
  int m=i/3*3, n=j/3*3;
  for (int p=0; p<3; p++)
    for (int q=0; q<3; q++)
      if (board[m+p][n+q]==k)
        return false;
  return true;
}
```
