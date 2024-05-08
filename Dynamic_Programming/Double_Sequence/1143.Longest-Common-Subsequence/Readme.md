# 1143.Longest-Common-Subsequence

- 考慮在text1[i]跟text2[j]的位置要如何做選擇?

通常是看text1[i]跟text2[j]是否相等，相等可以將該字符加入最長公共子序列中。

```
X X X X X X X i
X X X X X j
```

- 思考需要哪些狀態？

狀態需要i、j分別指向在text1、text2中位置。

- 定義dp數組含義。

照抄題目要求的目標。

```
dp[i][j]:  the length of their longest common subsequence with text1[1:i] and text2[1:j].
```

- 推導狀態轉移方程。

元素相等則取該元素，元素不等試著跳過text1[i]或text2[j]看剩餘序列中哪個最長公共子序列更長。

```
if (text1[i]==text2[j]) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
```

- 設定邊界條件及dp數組初值。

其中一個序列被縮減為空，跟另一序列無法產生公共子序列。

```
X X X X X i

dp[i][0]=0

X X j
dp[0][j]=0
```
