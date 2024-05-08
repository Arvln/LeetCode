# 62.Unique-Paths

到達當前格的路徑可能是從上或從左走來，需要座標當作狀態。

- 定義dp數組含義

```
dp[i][j]: the number of possible unique paths that the robot can take to reach the {i, j}.
```

- 定義狀態轉移方程

```
dp[i][j]=dp[i][j-1]+dp[i-1][j];
```

- 設定base case及dp數組初始值。

最上方及最左側格子都只有一種可能路徑，方便起見dp數組初值直接設為1。

```
dp[i][0]=1;
dp[0][j]=1;
```
