# 1105.Filling-Bookcase-Shelves

- 思考對於第i個元素可以做哪些選擇？

```
X X X X X [j X X X X i]
```

最後一份書本中的最大高度加上擺放前j-1本書的最小高度就是擺放所有書的最小高度。

- 思考需要哪些狀態？

需要書本位置i。

- 定義dp數組含義。

```
dp[i]: the minimum possible height that the i-th book can be after placing shelves.
```

- 推出狀態轉移方程。

```
dp[i]=min{ dp[i], dp[j-1]+maxHeigh[j:i] } for i=1,2,.. ,n
```

- 設定邊界條件及dp初始值。

擺放0本書的最小高度為0，要求最小值dp數組初始值給最大值。

```
dp[0]=0;
```

- 得出結論。

擺放n本書最小高度為dp[n]。
