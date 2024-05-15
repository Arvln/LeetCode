# 1278.Palindrome-Partitioning-III

題意明示要將所有元素分成k份，這類問題通常要從最後一份開始著手。

- 對於最後一份可以做哪些選擇？

```
[X X X X X X X X] [j X X X i]
```

求出最後一份字串修改為回文所需操作數，再加上前面k-1份字串修改為回文所需最小操作數。

- 思考需要哪些狀態？

標示當前元素位置i跟分割份數k。

- 定義dp數組含義。

```
dp[i][k]: the minimal number of characters that you need to change to divide the string[1:i] into k non-empty disjoint substrings such that each substring is a palindrome.
```

- 推導狀態轉移方程。

```
dp[i][k]=min{ dp[j-1][k-1]+to_palindrome(s[j:i]) } for j=k .. i
```

實際遍歷時注意越界問題，要保證dp[i][k]是有意義的，i>=k代表i字符最多分成k份子串，因此遍歷k時取min(i, K)作為上界。同理j-1>=k-1，至少要有k-1個字符才能分成k-1份子串，因此遍歷j時取k為下界。

- 如何計算最後一份子串修改為回文字串所需操作數?

直接寫一個helper函數計算最簡單，缺點是每次都要重新調用該函數，效率偏低。可以把這問題視為另一個區間dp問題預計算所需操作數。

- 設定邊界條件及dp數組初始值。

要求最小值，dp初值給最大值、空字串分0份修改為回文最小操作數為0作為初始條件。

```
dp[0][0]=0;
```

- 得出結論

整串字串切分為K份修改為回文最小操作數為dp[n][K]。
