# 123.Best-Time-to-Buy-and-Sell-Stock-III

- 對於第i個元素可以做哪些選擇？

```
X X X X X X [X] i
```

第i天有持倉可從前一天有持倉或前一天未持倉當天才買進轉移過來、第i天未持倉可從前一天未持倉或前一天持倉當天平倉轉移過來。

- 思考需要哪些狀態？

表示天數的狀態i、持股狀態status、交易次數k。其中持股狀態只有兩種可以開兩個數組簡化維度、天數只跟前一天狀態有關，再開兩個數組代替。

- 定義dp數組含義。

```
hold[k]: the maximum profit you can achieve with k transactions and hold stock.
sold[k]: the maximum profit you can achieve with k transactions without stock.
```

- 推導狀態轉移方程。

```
hold[k]=max(pre_hold[k], pre_sold[k-1]-price);
sold[k]=max(pre_sold[k], pre_hold[k]+price);
```

- 設定邊界條件及dp初始值。

尚未開始交易前空手的最大利潤為0、要求最大值dp初始值給最小值。

```
sold[0]=0;
```

- 得出結論。

最大利潤出現在最後一天空手且可能進行任意次數的交易。

```
int ret=0;
for (int k=1; k<=2; k++)
  ret=max(ret, sold[k]);
```
