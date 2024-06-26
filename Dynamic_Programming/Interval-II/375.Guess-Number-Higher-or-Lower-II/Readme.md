# 375.Guess-Number-Higher-or-Lower-II

假設數字範圍為1~5，隨便挑一個數保證會贏所需的錢有至少5種可能，5種可能中取最小值即是最少需花費的錢。該數字左右兩區間保證能猜中所需的最小花費要取最大的，如此才能保證贏得遊戲。

```
1 + [2,3,4,5]
2 + max([1], [3,4,5])
3 + max([1,2], [4,5])
4 + max([1,2,3], [5])
5 + [1,2,3,4]
```

- 對於第k個硬幣可以做哪些選擇？

```
[i X X X X] k [X X X j]
```

如選擇第k個硬幣，需要從兩側區間中保證會贏的最小花費取較大的一個，才能保證在目前的區間中贏得遊戲。

- 思考需要哪些狀態？

標示區間範圍的最左端i及最右端j。

- 定義dp數組含義。

```
dp[i][j]: the minimum amount of money you need to guarantee a win regardless of what number I pick between i and j.
```

- 推導狀態轉移方程。

```
dp[i][j]=min(dp[i][j], k+max(dp[i][k-1], dp[k+1][j]));
```

- 設定邊界條件及dp初始值。

當i大於j時不是可能區間，確保dp值不會越界或被取到。i等於j時的區間長度為1，不需花費必能贏得遊戲。

```
for (int i=1; i<=n; i++)
  dp[i][i]=0;
```

- 得出結論。

區間1~n保證贏得遊戲的最小花費為dp[1][n]。
