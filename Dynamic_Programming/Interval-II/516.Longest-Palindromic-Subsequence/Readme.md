# 516.Longest-Palindromic-Subsequence

- 可以做哪些選擇？

```
[i X X X X X X X j]
```

當s[i]跟s[j]相同，s[i:j]最長回文子序列長度為s[i+1:j-1]最長回文子序列長度加上s[i]跟s[j]。當s[i]不等於s[j]，s[i:j]最長回文子序列長度為s[i:j-1]最長回文子序列長度跟s[i+1:j]最長回文子序列長度中取大。

- 思考需要哪些狀態？

標示區間範圍的最左端i及最右端j。

- 定義dp數組含義。

```
dp[i][j]: the longest palindromic subsequence's length in s[i:j].
```

- 推導狀態轉移方程。

```
if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
else dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
```

- 設定邊界條件及dp初始值。

當i大於j時不是可能區間，遍歷字串長度從3開始，確保dp值不會越界。字串長度小於3當作邊界條件額外設定。要求最大值dp數組初始值設為最小值。

```
for (int i=0; i<n; i++)
  dp[i][i]=1;
for (int i=0; i+1<n; i++)
  dp[i][i+1]=1+(s[i]==s[i+1]);
```

- 得出結論。

整串字串的最長回文子序列長度為dp[0][n-1]。
