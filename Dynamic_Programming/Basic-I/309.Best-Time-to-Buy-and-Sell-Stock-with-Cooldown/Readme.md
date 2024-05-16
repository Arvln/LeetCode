# 309.Best-Time-to-Buy-and-Sell-Stock-with-Cooldown

- 思考在第i位如何做選擇？

```
X X X X X X X i
```

當天有持倉可從前一天有持倉或前一天未交易當天建倉轉移過來、當天未持倉可從前一天未持倉或前一天持倉當天平倉轉移過來、當天未交易可從前一天未交易或前一天平倉轉移過來。

- 思考需要哪些狀態？

第i天的可採取的交易取決於前一天交易狀態，需要表示時間的i跟交易狀態status。

- 定義dp數組含義。

```
dp[i][status]: the maximum profit you can achieve in i-th day with transaction status.
```

- 推導狀態轉移方程。

```
dp[i][hold]=max(dp[i-1][hold], dp[i-1][cool]-prices[i]);
dp[i][sold]=max(dp[i-1][sold], dp[i-1][hold]+prices[i]);
dp[i][cool]=max(dp[i-1][cool], dp[i-1][sold]);
```

- 設定邊界條件及dp初始值。

未開始交易前，不可能有持倉，因此dp[0][hold]設為最小值。空手或未交易的獲利均為0。

```
dp[0][sold]=0;
dp[0][cool]=0;
```

- 得出結論

最後一天空手或未交易的狀態中取獲利最大的。
