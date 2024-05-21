# 485.Max-Consecutive-Ones

- 思考在第i位如何做選擇？

```
X X X X X X [X] i
```

以第i位數字結尾的最大相連1的長度只跟前一位有關。

- 思考需要哪些狀態？

只需要位置i這項訊息。

- 明確dp數組的含義。

```
dp[i]: the maximum number of consecutive 1's in the array ending at nums[i].
```

- 推導狀態轉移方程。

```
if (nums[i]==1) dp[i]=dp[i-1]+1;
```

- 設定邊界條件及dp初始值。

dp數組初始值直接設為0。

- 得出結論。

最長連續1組成的子數組苦能以任意位置結尾，要對所有dp值取最大值。
