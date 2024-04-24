# 674.Longest-Continuous-Increasing-Subsequence

最長嚴格遞增子串長度只跟前一個元素結尾的子串長度有關，可以考慮dp思路。

- 對於第i個元素可以做哪些選擇？

```
X X X X X [X] i
```

假設前一個元素小於第i個元素，可以取前面一個元素結尾的最長嚴格遞增子串長度。

- 思考所需狀態。

需要子串結尾的位置i。

- 定義dp函數。

```
dp[i]: the length of the longest continuous increasing subsequence ending at nums[i].
```

照抄題目要求的內容。

- 考慮邊界狀況跟dp數組初始值。

以任意位置結尾的最長嚴格遞增子串長度最少為1。

```
vector<int>dp(n, 1);
```

最長嚴格遞增子串可能以任意字符結尾，全部搜一遍取最大值。
