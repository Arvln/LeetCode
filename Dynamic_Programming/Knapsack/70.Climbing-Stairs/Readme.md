# 70.Climbing-Stairs

- 對於第i步如何做選擇？

每次只能走1或2步，走到第i步的方法必是從走到第i-1步跟走到第i-2步方法數加總。

- 思考需要哪些狀態？

步數可重複走就是完全背包問題，狀態只需要開容量。

- 定義dp數組含義。

```
dp[i]: the number of distinct ways can you climb to i by climbing either 1 or 2 steps each time.
```

- 推導狀態轉移方程。

```
dp[i]=dp[i-1]+dp[i-2];
```

- 設定邊界條件及dp初始值。

從第2階開始遍歷，走到第0階跟第1階都算一種走法，dp數組初始值設為0方便加法運算。

```
dp[0]=1;
dp[1]=1;
```

- 得出結論。

走到第n階有dp[n]種走法。
