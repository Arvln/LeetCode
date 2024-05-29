# 115.Distinct-Subsequences

- 觀察在s[i]跟t[j]的位置要如何做選擇？

```
X X X X X X i
Y Y Y Y Y j
```

當s[i]等於t[j]時，取s[i]做為子序列代表子序列個數取決於s[1:i-1]跟t[1:j-1]可組成子序列個數。若不取s[i]做為子序列代表子序列個數取決於s[1:i-1]跟t[1:j]可組成子序列個數。當s[i]不等於t[j]時，只能不取s[i]。

- 思考需要哪些狀態？

推導狀態需要s當前元素的位置i和t當前元素的位置j。

- 明確狀態後可以定義dp數組含義，照抄題目要求的目標。

```
dp[i][j]: the number of distinct subsequences of s[1:i] which equals t[1:j].
```

- 推導狀態轉移方程。

```
if (s[i]==t[j]) dp[i][j]+=dp[i-1][j-1];
dp[i][j]+=dp[i-1][j];
```

- 設定邊界條件及dp數組初始值。

t為空串時可以組成一個子序列，dp數組初始值設為0方便做加法運算。

```
X X X X X i
-

dp[i][0]=1;
```

- 得出結論

s[1:m]跟t[1:n]可構成等於t[1:n]的子序列個數為dp[m][n]。
