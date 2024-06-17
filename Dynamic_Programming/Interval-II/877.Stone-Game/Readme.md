# 877.Stone-Game

### 貪心

石頭堆數只有偶數個，先手玩家必會在石頭堆數是偶數時選擇，因此可做出最優選擇。不可能平手情況下，先手玩家必勝。

### 區間dp

- 可以做哪些選擇？

```
[i X X X X X X X j]
```

Alice可在piles[i]加上[i+1:j]可得最大得分跟piles[j]加上[i:j-1]可得最大得分中挑一個最大的得分數。

- 思考需要哪些狀態？

標示區間範圍的最左端i及最右端j。

- 定義dp數組含義。

```
dp[i][j]: the maximum number of stones Alice can take in piles[i:j].
```

- 推導狀態轉移方程。

```
dp[i][j]=max(dp[i][j-1]+piles[j], dp[i+1][j]+piles[i]);
```

- 設定邊界條件及dp初始值。

當i大於j時不是可能區間，遍歷區間長度從2開始，確保dp值不會越界。區間長度為1當作邊界條件額外設定。狀態會從小區間往大區間轉移不需設置dp數組初始值。

```
for (int i=0; i<n; i++)
  dp[i][i]=piles[i];
```

- 得出結論。

Alice在完整區間內最大得分dp[0][n-1]超過石頭總數的一半即為獲勝。
