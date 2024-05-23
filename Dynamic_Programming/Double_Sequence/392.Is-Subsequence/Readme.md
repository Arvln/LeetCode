# 392.Is-Subsequence

- 考慮在s[i]跟t[j]的位置要如何做選擇?

通常是看s[i]跟t[j]是否相等，相等可互相匹配。不相等則看t[j-1]是否能跟s[i]匹配。

```
X X X X X i
X X X X X X j
```

- 思考需要哪些狀態？

狀態需要i、j分別指向在s、t中位置。

- 定義dp數組含義。

照抄題目要求的目標。

```
dp[i][j]: s[1:i] is a subsequence of t[1:j].
```

- 推導狀態轉移方程。

元素相等匹配該元素，元素不等試著跳過t[j]，往前看t[j-1]是否能跟s[i]匹配。

```
if (s[i]==t[j]) dp[i][j]=dp[i-1][j-1];
else dp[i][j]=dp[i][j-1];
```

- 設定邊界條件及dp數組初值。

當s被縮減為空，代表t可以成功匹配s，則s是t的子序列。當t被縮減為空，代表t不能成功匹配s，則s不是t的子序列，dp初始值設為false。

```
X X X X X i

dp[i][0]=false;

X X j
dp[0][j]=true;
```

- 得出結論。

s[1:m]是否能被t[1:n]匹配要看dp[m][n]。
