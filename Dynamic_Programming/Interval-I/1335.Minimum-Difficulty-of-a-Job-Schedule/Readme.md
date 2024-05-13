# 1335.Minimum-Difficulty-of-a-Job-Schedule

題意明示要將所有元素分成k份，這類問題通常要從最後一份開始著手。

- 對於最後一份可以做哪些選擇？

```
[X X X X X X X] [j X X X i]
```

取出最後一份所有元素中的最大值當作最後一份困難度，再加上前面k-1份最小困難度。

- 思考需要哪些狀態？

標示當前元素位置i跟分割份數k。

- 定義dp數組含義。

```
dp[i][k]: the minimum difficulty of a job schedule ending at jobDifficulty[i] divided into k splits.
```

- 推導狀態轉移方程。

```
dp[i][k]=min{ dp[j-1][k-1]+max_diff(jobDifficulty, j, i) } for j=k .. i
```

- 設定邊界條件及dp數組初始值。

要求最小值，dp初值給最大值、0份工作分0天完成困難度為0作為初始條件。

```
dp[0][0]=0;
```

- 得出結論

所有n份工作切分為d份完成的最小困難度為dp[n][d]。
