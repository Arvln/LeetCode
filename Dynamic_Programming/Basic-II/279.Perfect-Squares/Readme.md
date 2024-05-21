# 279.Perfect-Squares

以16為例，有4種可能組合。要在遞推關係中求最小值可以猜到用dp思路。

```
1 + [15]
4 + [12]
9 + [7]
16 + [0]
```

- 思考對於任一個完全平方數可以做哪些選擇？

每個完全平方數可選擇取或不取，取決於哪一種構造目標和需要最少的完全平方數。

- 思考需要哪些狀態？

所有完全平方數的和sum。

- 定義dp數組含義。

```
dp[s]: the least number of perfect square numbers that sum to s.
```

- 推出狀態轉移方程。

```
for (int sum=1; sum<=n; sum++)
    for (int i=1; i*i<=sum; i++)
        dp[sum]=min(dp[sum], dp[sum-i*i]+1);
```

- 設定邊界條件及dp初始值。

要湊0只需要0種完全平方數當作邊界條件，要求最小值dp數組初始值設為最大值。

- 得出結論。

湊齊目標和n的最小完全平方數個數為dp[n]。
