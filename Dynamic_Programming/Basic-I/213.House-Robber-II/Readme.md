# 213.House-Robber-II

房屋首尾相連，可分情況討論，一種是第一棟房不搶，另一種是最後一棟房不搶。在此前提下，剩餘房屋搶法不受限制，思路跟 #198 一模一樣。

```
N [X X X X X X i]
[X X X X X X i] N
```

- 對於第i個元素可以做哪些選擇？

```
X X X X X X [X] i
```

第i棟房為止最大獲利只依賴於前一棟房為止最大獲利。搶這棟房最大獲利取決於前一間房不搶的最大獲利加上這間房內的現金。不搶這棟房最大獲利取決於搶前一間房的最大獲利跟不搶前一間房的最大獲利中取一個最大值。

- 思考需要哪些狀態？

房屋位置i、搶劫狀態status。

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

dp初始值設為0方便做加法運算跟取最大值。

- 得出結論。

最大獲利也分情況討論，第一間房不搶的最大獲利就是第n間房搶或不搶中取最大獲利。最後一間房不搶的最大獲利就是第n-1間房搶或不搶中取最大獲利。兩種情況中的最大獲利再取最大值就是最大可能獲利。
