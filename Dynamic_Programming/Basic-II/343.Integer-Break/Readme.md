# 343.Integer-Break

- 思考對於第i個元素可以做哪些選擇？

```
X X X j X X X i
```

往前隨便找一個j，假設最後一個分割數字為i-j，則元素和為j的最大乘積*(i-j)就有機會更新元素和為i的最大乘積。

- 思考需要哪些狀態？

元素和i。

- 定義dp數組含義。

```
dp[i]: given an integer i, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
```

- 推出狀態轉移方程。

```
dp[i]=max(dp[i], dp[j]*(i-j));
```

- 設定邊界條件及dp初始值。

元素和為2或3時再做拆分會讓乘積變小，因此拆到2或3就不該再做拆分。求最大值dp數組初始值給最小。

```
dp[2]=2;
dp[3]=3;
```

- 得出結論。

元素和為n，拆分為k份的最大乘積為dp[n]。k最小為2，因此元素和2或3是例外，需要特判。
