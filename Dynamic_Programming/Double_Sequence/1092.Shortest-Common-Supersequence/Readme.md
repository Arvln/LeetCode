# 1092.Shortest-Common-Supersequence

求最短公共超級序列大致分為兩種思路。一種是求最短公共超級序列長度、另一種是求最長公共子序列長度。已知長度後，再模擬動態規劃選擇字符的過程就可以建構出最短公共超級串。

### 求最短公共超級序列長度

- 考慮在str1[i]跟str2[j]的位置要如何做選擇?

通常是看str1[i]跟str2[j]是否相等，相等可以將該字符加入最短公共超級序列中，若兩字符不相等，取跟剩餘部分可以構成較短公共超級序列的字符。

```
Z Z Z Z Z Z Z Z Z Z ?

X X X X X i
Y Y Y Y j
```

- 思考需要哪些狀態？

狀態需要i、j分別指向在str1、str2中位置。

- 定義dp數組含義。

照抄題目要求的目標字串長度。

```
dp[i][j]: the number of the shortest string that has both str1[1:i] and str2[1:j] as subsequences.
```

- 推導狀態轉移方程。

```
if (str1[i]==str2[j]) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=min(dp[i-1][j], dp[i][j-1])+1;
```

- 設定邊界條件及dp數組初值。

要求最短公共超級序列長度，dp數組初始值設為最大值。當其中一個字串為空時，另一個字串就是最短公共超級序列。

```
for (int i=0; i<=m; i++)
    dp[i][0]=i;
for (int j=0; j<=n; j++)
    dp[0][j]=j;
```

- 得出結論。

模擬動態規劃計算最短公共超級序列長度的過程，構造最短公共超級串。


### 最長公共子序列長度

- 考慮在str1[i]跟str2[j]的位置要如何做選擇?

通常是看str1[i]跟str2[j]是否相等，相等可以將該字符加入最長公共子序列中，若兩字符不相等，取跟剩餘部分可以構成最長公共子序列的長度。

```
X X X X X i
Y Y Y Y j
```

- 思考需要哪些狀態？

狀態需要i、j分別指向在str1、str2中位置。

- 定義dp數組含義。

```
dp[i][j]: the number of longest common subsequence between str1[1:i] and str2[1:j].
```

- 推導狀態轉移方程。

```
if (str1[i]==str2[j]) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
```

- 設定邊界條件及dp數組初值。

要求最長公共子序列長度，dp數組初始值設為最小值。當其中一個字串為空時，空串就是最長公共子序列。

```
for (int i=0; i<=m; i++)
    dp[i][0]=0;
for (int j=0; j<=n; j++)
    dp[0][j]=0;
```

- 得出結論。

模擬動態規劃計算最長公共子序列長度的過程，構造最短公共超級串。
