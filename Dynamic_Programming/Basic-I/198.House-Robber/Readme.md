# 198.House-Robber

- 思考在第i位如何做選擇？

```
X X X X X X X i
```

搶第i間房的最大收益取決於不搶前一間房的最大收益加上這間房內的現金。不搶第i間房的最大收益取決於搶前一間房的最大收益跟不搶前一間房的最大收益中取大。

- 思考需要哪些狀態？

第i天的可採取的策略取決於前一天策略，需要表示房屋位置的i跟策略狀態status。

- 定義dp數組含義。

```
rob[i]:  the maximum amount of money you can rob tonight without alerting the police with robing i-th house.
norob[i]: the maximum amount of money you can rob tonight without alerting the police without robing i-th house.
```

- 推導狀態轉移方程。

```
rob[i]=norob[i-1]+nums[i];
norob[i]=max(rob[i-1], norob[i-1]);
```

- 設定邊界條件及dp初始值。

dp初始值設為0方便加法運算跟取最大值。

- 得出結論

整晚搶劫的最大收益取決於rob[n]跟norob[n]中較大的收益。
