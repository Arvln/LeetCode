# 416.Partition-Equal-Subset-Sum

要把所有元素分成兩個等和子集，換個想法是挑出部分元素讓和等於 sum/2，對於第 i 個元素思考一個 dp 數組定義。

dp[i][s] => 從第 1 個到第 i 個元素是否存在方法可以讓和為 s

對於第 i 個元素要湊齊和為 s 有兩種可能：

I. 第 i-1 個元素已經湊齊和為 s，第 i 個元素不選
II. 第 i-1 個元素已經湊齊和為 s-nums[i]，第 i 個元素必選

推出狀態轉移方程

```
dp[i][j]=dp[i-1][j]||nums[i-1][j-nums[i]];
```

處理越界問題及初始值

```
dp[0][0]=true;

for (int i=1; i<=n; i++)
  for (int j=0; j<=sum/2; j++)
    dp[i][j]=dp[i-1][j]||(j>=nums[i]&&dp[i-1][j-nums[i]]);
```

返回第一個到第 n-1 個元素和為 sum/2 的 dp 值

dp[n][sum/2]
