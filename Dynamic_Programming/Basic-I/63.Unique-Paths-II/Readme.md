# 63.Unique-Paths-II

- 對於任意格子可以做哪些選擇？

到達當前格的路徑可能是從上或從左走來。

- 思考需要哪些狀態？

格子所在座標{i, j}。

- 定義dp數組含義。

```
dp[i][j]: the number of possible unique paths that the robot can take to reach the {i, j}.
```

- 推導狀態轉移方程。

```
if (obstacleGrid[i][j]==0) dp[i][j]=dp[i][j-1]+dp[i-1][j];
```

- 設定邊界條件及dp初始值。

到達最左上角格子{0, 0}路徑數當作邊界條件，dp初始值設為0方便做加法運算。

```
dp[0][0]=obstacleGrid[i][j]==0;
```

- 得出結論。

到達最右下角格子{m-1, n-1}總路徑數為dp[m-1][n-1]。
