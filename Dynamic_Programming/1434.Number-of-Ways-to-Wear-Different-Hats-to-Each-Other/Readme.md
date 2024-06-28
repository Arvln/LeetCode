# 1434.Number-of-Ways-to-Wear-Different-Hats-to-Each-Other

根據提示人數最多僅10人，強烈暗示可以用狀態壓縮dp的思路，10個bit就能存儲每個人有沒有戴帽子的狀態。因此可逐個看每頂帽子被選中後可以貢獻多少方法數。

- 對於第i頂帽子可以做哪些選擇？

```
X X X X X [X] i
```

第i-1頂帽子被選中的總搭配數可以完全轉移到第i頂帽子被選中的總搭配數。

- 思考需要哪些狀態？

當前帽子的位置訊息i跟每個人持有帽子的狀態p。

- 定義dp數組含義。

```
dp[i][p]: the number of ways that n people wear different hats to each other in i-th hat with pattern p.
```

- 推導狀態轉移方程。

```
dp[i][p]=dp[i][p]+dp[i-1][p'];
```

- 設定邊界條件及dp初始值。

沒有人戴帽子算一種方法。為方便做加法運算dp數組初始值給0。

```
dp[0]=1;
```

- 得出結論。

總共n個人都有戴帽子的總方法數dp[(1<<n)-1]。
