# 72.Edit-Distance

- 觀察在word1[i]跟word2[j]的位置要如何做選擇？

```
X X X X X X i
Y Y Y Y Y j
```

當word1[i]等於word2[j]時，不需做任何操作。兩個字符不相等時，可插入、刪除或替換字符。

- 思考需要哪些狀態？

推導狀態需要word1當前元素的位置i和word2當前元素的位置j。

- 明確狀態後可以定義dp數組含義，照抄題目要求的目標。

```
dp[i][j]: the minimum number of operations required to convert word1[1:i] to word2[1:j].
```

- 推導狀態轉移方程。

word1[i]不等於word2[j]時，插入操作由插入字符跟word2[j]配對、刪除操作則刪除word1[i]、替換操作則替換word1[i]跟word2[j]配對，取最小操作數再加上該操作數。若相等不需做任何操作即可配對。

```
if (word1[i]==word2[j]) dp[i][j]=dp[i-1][j-1];
else dp[i][j]=min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])+1;
```

- 設定邊界條件及dp數組初始值。

當其中一串為空時，要讓兩串相等只能採刪除操作將另一串刪為空串。要求最小值dp數組初始值給最大值。

```
X X X X X X i
-

dp[i][0]=i;

-
Y Y Y Y Y j

dp[0][j]=j;
```

- 得出結論

讓word1[1:m]跟word2[1:n]相等所需最小操作數為dp[m][n]。
