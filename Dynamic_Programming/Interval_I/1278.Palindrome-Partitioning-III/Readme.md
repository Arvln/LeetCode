# 1278.Palindrome-Partitioning-III

求最值的問題思路往 dp 靠，直接把要求的結果當作 dp 數組的定義

```
dp[i][k]: the minimal number of characters that you need to change to divide the string into k non-empty disjoint substrings such that each substring is a palindrome
```

對於第 i 個元素找出最後一份的起始點 j 計算最後一份要改幾個字符可以形成回文串

```
X X X X X X X [j X X X i]

to_palindrome(s[j:i]);
```

推出狀態轉移方程

```
dp[i][k]=min{ dp[j-1][k-1]+to_palindrome(s[j:i]) } for j=k .. i
```

處理邊界問題及初始值，總共有 i 個元素，最多可以分成 min(i, K) 份，前 k-1 份最少要各有一個元素，j 最多可以從 k 開始切分

```
dp[0][0]=0;
for (int i=1; i<=n; i++)
  for (int k=1; k<=min(i, K); k++)
    for (int j=k; j<=i; j++)
      dp[i][k]=min(dp[i][k], dp[j-1][k-1]+to_palindrome(s, j, i));
```

返回第 n-1 個元素切分為 K 份的 dp 值

dp[n][K]
