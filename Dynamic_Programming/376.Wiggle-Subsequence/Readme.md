# 376.Wiggle-Subsequence

求子序列的最大值，思路大概是跟 dp 有關，對於第 i 個元素思考 dp 數組定義，直接把要求的結果當作定義

```
dp[i]: the length of the longest wiggle subsequence of nums ending at nums[i]
```

只知道是第 i 個元素的資訊還不能判斷是否與第 i-1 個元素的差值是否上下交替的，需要再加一個狀態紀錄當前元素跟前一個元素差值是正或負

```
dp[i][j]: the length of the longest wiggle subsequence of nums ending at nums[i] and the last difference is j
```

當第 i 個元素跟第 i-1 個元素差值為正，代表以第 i 個元素結尾差值為正的狀態是以第 i-1 個元素結尾差值為正的狀態跟以第 i-1 個元素結尾差值為負加上當前為正的差值的狀態中取最大值，反之類推，推出狀態轉移方程

```
if (nums[i]>nums[i-1])
  dp[i][pos] = max(dp[i-1][pos], dp[i-1][neg]+1);
else if (nums[i]<nums[i-1])
  dp[i][neg] = max(dp[i-1][neg], dp[i-1][pos]+1);
```

第 i 個元素狀態可以化簡

```
if (nums[i]>nums[i-1])
  pos = max(pre_pos, pre_neg+1);
else if (nums[i]<nums[i-1])
  neg = max(pre_neg, pre_pos+1);
```

結果在第 i 個元素結尾差值為正跟第 i 個元素結尾差值為負中取大
