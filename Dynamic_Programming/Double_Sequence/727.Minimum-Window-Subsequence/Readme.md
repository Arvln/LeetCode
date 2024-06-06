# 727.Minimum-Window-Subsequence

- 考慮在S[i]跟T[j]的位置要如何做選擇?

通常是看S[i]跟T[j]是否相等，相等則以S[i]結尾包含T[1:j]的最小子串長度就是以S[i-1]結尾包含T[1:j-1]的最小子串長度加上S[i]。若不相等則以S[i]結尾包含T[1:j]的最小子串長度為以S[i-1]結尾包含T[1:j]的最小子串長度加上S[i]。

```
X X X X X X X i
Y Y Y Y Y j
```

- 思考需要哪些狀態？

狀態需要i、j分別指向在S、T中位置。

- 定義dp數組含義。

照抄題目要求的目標。

```
dp[i][j]: the minimum substring W ending at s[i], so that T[1:j] is a subsequence of W.
```

- 推導狀態轉移方程。

```
if (S[i]==T[j]) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=dp[i-1][j]+1;
```

- 設定邊界條件及dp數組初值。

T為空串時以S[i]結尾包含T的最小子串長度為0當作邊界條件，要求最小值dp數組初始值給最大值。

```
X X X X X i
-

dp[i][0]=0
```

- 得出結論。

包含T[1:j]的最小子串可能以任意字符結尾，需要過一遍所有字符找出最小子串長度並紀錄子串結尾的索引就能構建出該子串。

```
min { dp[i][n] } for i=1,2, ..,m
```
