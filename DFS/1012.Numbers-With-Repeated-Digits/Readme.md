# 1012.Numbers-With-Repeated-Digits

給一個數字 n，求在[1..n]範圍內的所有數中至少包含一個重複數字的數有幾個，正難則反，換個想法是找出沒有重複數字的數的總數再跟 n 相減就行

```
result = n - no repeat
```

找出所有不重複數字的數有幾個就是 #2376，思路一模一樣，先算出一到三位數總共有幾個不重複數字的數，可參考 #357 以組合數學做計算

```
string s=to_string(n);
for (int len=1; len<=s.size()-1; len++)
  ret+=A(10, len)-A(9, len-1);
```

四位數需要逐個數來討論，舉 2376 為例，最高位是 2，只需要討論 0、1、2 三個數，0 是不合法的數字，1 開頭不重複數字的數的總數可直接用組合數求解，2 開頭遞歸到下一位數字處理

```
2 3 7 6
X X X X
0 -> 0XXX -> continue
1 -> 1XXX -> A(10-1, 4-1)
2 0 -> 20XX -> A(10-2, 4-2)
  1
  3 ...
```

用 DFS 走過一遍字串，每個數只能出現一次，帶上一個 visited 數組紀錄一下，小於當前數字的數都可以做剪枝，改用組合數學求解

```
void dfs(string& s, int i, vector<int>& visited)
{
  int n=s.size();

  for (int k=0; k<=9; k++)
  {
    if (i==0&&k==0) continue;
    if (visited[k]) continue;

    if (k<s[i]-'0')
      ret+=A(10-(i+1), n-(i+1));
    else if (k==s[i]-'0')
    {
      visited[k]=1;
      dfs(s, i+1, visited);
      visited[k]=0;
    }
  }
}
```

邊界條件是當遍歷到最後一個字符，相當於找到最後一個不重複數字 2376，更新結果後返回

```
if (i>=n)
{
  ret+=1;
  return;
}
```
