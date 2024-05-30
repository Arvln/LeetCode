# 1186.Maximum-Subarray-Sum-with-One-Deletion

求最大子數組和就是用Kadane's。

- 思考在第i位如何做選擇？

```
X X X X X X [X] i
```

以nums[i]結尾的最大子數組和是從nums[i]跟nums[i]加上以nums[i-1]結尾的最大子數組和中取大。

- 思考需要哪些狀態？

需要結尾數字位置i跟刪除數字次數k。

- 明確dp數組的含義。

```
dp[i][k]: the maximum sum for a non-empty subarray ending at nums[i] with k element deletion.
```

- 推導狀態轉移方程。

```
dp[i][0]=max(arr[i], dp[i-1][0]+arr[i]);
dp[i][1]=max({arr[i], dp[i-1][0], dp[i-1][1]+arr[i]});
```

- 設定邊界條件及dp初始值。

要求最大值dp數組初始值給最小值。

- 得出結論。

最大子數組和可能以任意數字結尾且不一定要刪除數字，因此遍歷一遍所有dp值取最大和。

```
max{ dp[i][0], dp[i][1] } for i=1,2, ..,n
```
