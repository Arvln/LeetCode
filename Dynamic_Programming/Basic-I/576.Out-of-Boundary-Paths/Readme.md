# 576.Out-of-Boundary-Paths

求有多少條走出界的路徑，換個角度想就是求從界外有多少條可走到該點路徑。

- 對於位置{i, j}的球有哪些路徑可以走到？

只要累加相鄰四個方向的格子路徑數，就是可以走到該位置的路徑總數。

- 思考需要哪些狀態？

只需要矩陣位置i, j。

- 明確dp數組的含義。

```
dp[i][j]: the number of paths to move the ball from out of the grid boundary to grid[i][j].
```

- 推導狀態轉移方程。

```
dp[i][j]=pre_dp[i-1][j]+pre_dp[i][j-1]+pre_dp[i+1][j]+pre_dp[i][j+1];
```

- 設定邊界條件及dp初始值。

不用邊界條件，dp初始值設為0方便做加法運算。

- 得出結論。

從{startRow, startColumn}走出界外總路徑數為dp[startRow][startColumn]。
