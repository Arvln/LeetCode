# 174.Dungeon-Game

- 在{i, j}位置可以做哪些選擇？

```
{i, j} <- {i, j+1}
       <- {i+1, j}
```

騎士只向右或下走，右方或下方相鄰格最小血量中挑一個更小的就是當前格出發到達右下角的最小安全血量，安全血量最小為1，因為不論後面補藥有多少，只需要一滴血就能平安抵達。

- 思考需要哪些狀態？

標示位置訊息的i、j。

- 定義dp數組含義。

```
dp[i][j]: the minimum initial health so that knight can rescue the princess start from dungeon[i][j].
```

- 推導狀態轉移方程。

```
dp[i][j]=min(dp[i][j+1]-dungeon[i][j+1], dp[i+1][j]-dungeon[i+1][j]);
```

- 設定邊界條件及dp初始值。

特判所有越界情況，dp[m-1][n-1]至少要有1才能活著抵達。

```
dp[m-1][n-1]=1;
```

- 得出結論。

從最左上角格子出發抵達最右下角格子至少要dp[0][0]的血量。
