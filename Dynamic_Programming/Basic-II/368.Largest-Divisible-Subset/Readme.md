# 368.Largest-Divisible-Subset

要構造滿足某條件最長序列，常規思路是先求出最長長度是多少，已知最長長度再思考如何構造該序列。

- 思考對於第i個元素可以做哪些選擇？

```
X X X j X X X i
```

當nums[i]可被nums[j]整除，要讓以nums[i]結尾最大長度跟nums[j]結尾最大長度產生關聯，最直覺的做法就是先幫序列排序。有序的情況下，nums[j]結尾最大長度加上nums[i]的長度就有機會更新以nums[i]結尾最大長度。

- 思考需要哪些狀態？

結尾元素位置i。

- 定義dp數組含義。

```
dp[i]: the number of the largest subset that every pair of elements in subset satisfies subset[i]%subset[j]==0 or subset[j]%subset[i]==0.
```

- 推出狀態轉移方程。

```
if (nums[i]%nums[j]==0) dp[i]=max(dp[i], dp[j]+1);
```

- 設定邊界條件及dp初始值。

以任意元素結尾且滿足條件的最長序列長度最少為1，因此dp初始值給1。

```
vector<int>dp(n, 1);
```

- 得出結論。

題目要求要構造該序列，這也很簡單，只要在每次以nums[j]結尾最大長度更新以nums[i]結尾最大長度時，順便記錄一下觸發更新最大值的前驅節點位置就行。

```
if (nums[i]%nums[j]==0)
{
  dp[i]=max(dp[i], dp[j]+1);
  if (dp[i]==dp[j]+1) prev[i]=j;
}
```

滿足條件的最長序列可能以任意元素結尾，搜一遍dp數組可知結尾元素位置i。

```
max{ dp[i] } for i=0,1,.. ,n-1
```

已知滿足條件的最長序列結尾元素位置i，順著前驅節點往前構造出序列就行。
