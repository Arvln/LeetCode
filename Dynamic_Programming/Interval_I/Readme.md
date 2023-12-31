# Interval I

給出一個序列，要將序列分割為 k 個區間，求所有區間的最優性質，用要求的結果定義 dp 數組

```
dp[i][k]: 前i個元素分割為k個區間的最優值
```

思路是找最後一個區間的起始點 j 將序列分割為[0, j-1]共含有 k-1 份跟最後一份[j, i]兩部分

```
X X X X X X X [j X X X i]
```

第一層循環遍歷序列元素，第二層循環遍歷分割份數，最多可分成 min(i, K) 份，第三層循環遍歷所有切分點 j ，假設前 k-1 份最少各有 1 個元素，最後一個區間最少從 k 開始切

```
for (int i=1; i<=n; i++)
  for (int k=1; k<=min(i, K); k++)
    for (int j=k; j<=i; i++)
      dp[i][k]=max/min{ dp[i][k], helper(dp[j-1][k-1], j, i) };
```

返回第 n-1 個元素切分為 K 份的 dp 值

dp[n][K]
