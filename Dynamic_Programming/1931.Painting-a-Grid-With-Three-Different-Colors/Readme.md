# 1931.Painting-a-Grid-With-Three-Different-Colors

跟 #1411 思路一模一樣，這一輪狀態只跟前一輪狀態有關，每一行最多5格且每一格只有3種顏色可以上，因此最多僅需3^5就能列舉所有可能的狀態，可用狀態壓縮dp的思路另開一個維度表示狀態。

- 對於第i行可以做哪些選擇？

```
X X X X X [X] i
```

累加第i-1行有效上色數可以得出第i行有效上色數。

- 思考需要哪些狀態？

紀錄當前行數訊息i跟顏色分布狀態p。

- 定義dp數組含義。

```
dp[i][p]: the number of ways you can paint i-th column with pattern p.
```

- 推導狀態轉移方程。

```
dp[i][p]=dp[i][p]+dp[i-1][p'];
```

- 設定邊界條件及dp初始值。

第1行的有效上色數只要兩旁顏色不同就是1種有效上色方式，沒有前一行需要考慮。為方便做加法運算dp數組初始值給0。

```
for (int p=0; p<N; p++)
  if (colValid(p)) dp[p]=1;
```

- 得出結論。

有效上色方法數為最後一行有效上色數加總。

```
for (int p=0; p<N; p++)
  if (colValid(p)) ret=ret+dp[p];
```
