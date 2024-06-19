# 474.Ones-and-Zeroes

要在一系列不可複選的物品中挑若干個滿足指定容量，屬於01背包問題。

- 對於第i個物品如何做選擇？

```
X X X X X {x, y}
```

可以選擇取或不取該物品，兩種對應的花費及長度都可以進行狀態轉移。

- 思考需要哪些狀態？

01背包問題需要代表物品位置的狀態i、0的個數m、1的個數n。

- 定義dp數組含義。

```
dp[i][m][n]: the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset in nums[0:i].
```

- 推導狀態轉移方程。

```
dp[i][m][n]=max(dp[i][m][n], dp[i-1][m-x][n-y]+1);
```

- 設定邊界條件及dp初始值。

要算最長長度，dp數組初始值給0就行。

- 得出結論。

最多只能有m個0跟n個1的最長子的最長子序列長度就是dp[m][n]。
