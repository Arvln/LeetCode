# 1425.Constrained-Subsequence-Sum

求子序列最大和跟求子數組最大和思路很相似，都可以應用Kadane's的思想再結合 #1696 的思路就行。

- 思考對於第i個元素可以做哪些選擇？

```
X X X X [X X X] i
```

依照Kadane's的思想，以nums[i]為結尾的最大子序列和必是在nums[i]、以[i-k:i-1]結尾的子序列和中挑一個最大值加上nums[i]的其中一個。

- 思考需要哪些狀態？

子序列結尾的位置i。

- 定義dp數組含義。

```
dp[i]: the maximum sum of a non-empty subsequence of nums[0:i] such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
```

- 推出狀態轉移方程。

```
dp[i]=max(nums[i], dp[j]+nums[i]) for j=i-k, i-k+1, .., i-1
```

- 設定邊界條件及dp初始值。

不需設置。

- 得出結論。

最大子序列和可能以任意位置結尾，遍歷一遍所有dp值取最大值。
