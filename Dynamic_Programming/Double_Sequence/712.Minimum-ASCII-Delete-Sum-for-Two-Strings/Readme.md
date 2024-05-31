# 712.Minimum-ASCII-Delete-Sum-for-Two-Strings

- 觀察在s1[i]跟s2[j]的位置要如何做選擇？

```
X X X X X X i
Y Y Y Y Y j
```

當s1[i]等於s2[j]時，不需做任何操作。兩個字符不相等時，可刪除s1[i]或s2[j]。

- 思考需要哪些狀態？

推導狀態需要s1當前元素的位置i和s2當前元素的位置j。

- 明確狀態後可以定義dp數組含義，照抄題目要求的目標。

```
dp[i][j]: the lowest ASCII sum of deleted characters to make s1[1:i] and s2[1:j] equal.
```

- 推導狀態轉移方程。

s1[i]不等於s2[j]時，刪除s1[i]或s2[j]，取可讓剩餘部分相等的最小ASCII和再加上被刪除字符ASCII值。若相等不需做任何操作即可配對。

```
if (s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1];
else dp[i][j]=min(dp[i-1][j]+s1[i], dp[i][j-1]+s2[j]);
```

- 設定邊界條件及dp數組初始值。

當其中一串為空時，要讓兩串相等只能採刪除操作將另一串刪為空串。要求最小值dp數組初始值給最大值。

```
X X X X X X i
-

dp[i][0]=dp[i-1][0]+s1[i];

-
Y Y Y Y Y j

dp[0][j]=dp[0][j-1]+s2[j];
```

- 得出結論

讓s1[1:m]跟s2[1:n]相等的最小ASCII和為dp[m][n]。
