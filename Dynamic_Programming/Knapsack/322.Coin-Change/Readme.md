# 322.Coin-Change

- 對於第i個硬幣如何做選擇？

可以取或不取該硬幣，取決於哪種方式可以保持所需硬幣數最少。

- 思考需要哪些狀態？

硬幣可複選就是完全背包問題，狀態只需要開容量。

- 定義dp數組含義。

```
dp[amount]: he fewest number of coins that you need to make up that amount.
```

- 推導狀態轉移方程。

```
dp[amount]=min(dp[amount], dp[amount-coin]+1);
```

- 設定邊界條件及dp初始值。

要湊0元所需最少硬幣數為0當作邊界條件、要取最小值dp數組初始值設為最大值。

```
dp[0]=0;
```

- 得出結論。

湊amount元所需最少硬幣數為dp[amount]。
