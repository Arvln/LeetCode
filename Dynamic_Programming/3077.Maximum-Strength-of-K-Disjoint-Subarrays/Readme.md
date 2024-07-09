# 3077.Maximum-Strength-of-K-Disjoint-Subarrays

要從所有元素中挑出k份，通常要從最後一份開始著手。處理最後一份需要再遍歷所有可能的分割點j，為N^3的dp。

### N^3常規暴力解

- 對於最後一份可以做哪些選擇？

```
[X X X X X X X] [j X X X i]
```

為方便計算第k份的強度，可先將數組反轉，第k份的強度就是pow(-1, k+1)*sum[j:i]*k再加上前j-1個元素分成k-1份的最大強度就有機會更新前i個元素分成k份的最大強度。

- 思考需要哪些狀態？

標示當前元素位置i跟分割份數k。

- 定義dp數組含義。

```
dp[i][k]: the maximum possible strength in nums[1:i] split into k subarrays.
```

- 推導狀態轉移方程。

```
dp[i][k]=max{ dp[j-1][k-1]+pow(-1, k+1)*sum[j:i]*k } for j=k .. i
```

- 設定邊界條件及dp數組初始值。

不一定要全選所有元素，因此前i個元素分成0份最大強度為0作為邊界條件，要求最大值，dp初值給最小值。

```
for (int i=0; i<=n; i++)
  dp[i][0]=0;
```

- 得出結論

不一定要全選所有元素，因此在在前i個元素可以分成K份的最大強度中取最大值。

```
for (int i=1; i<=n; i++)
  ret=max(ret, dp[i][K]);
```

遍歷完所有元素跟分割份數後，數據量達到1e6，再遍歷最後一份的所有分割點j必定會TLE，因此時間複雜度需要壓在N^2。代表dp必須圍繞最後一個元素來定義而非最後一個子數組。

### N^2優化解

- 對於最後一個元素i可以做哪些選擇？

```
[X X X X X X X] [i]
```

為方便計算最後一個元素i的強度，可先將數組反轉，最後一個元素i的強度就是pow(-1, k+1)*nums[i]*k。不一定要取所有元素，因此最後一個元素可以取或不取。

- 思考需要哪些狀態？

標示當前元素位置i、分割份數k、最後一個元素i是否在第k個子數組中的狀態status。

- 定義dp數組含義。

```
dp[i][k][status]: the maximum possible strength in nums[1:i] split into k subarrays and nums[i] is or not in k-th subarray.
```

- 推導狀態轉移方程。

若最後一個元素nums[i]不取，dp[i][k][0]直接從dp[i-1][k][0]跟dp[i-1][k][1]中挑一個最大值就行。若最後一個元素nums[i]要取，可以分兩種情況討論，一種是最後一個元素自成一個子數組，此時dp[i][k][1]從dp[i-1][k-1][0]跟dp[i-1][k-1][1]挑一個最大值加上nums[i]的最大強度就行。另一種是最後一個元素nums[i]跟前面第k個子數組合併成最後一個子數組，此時dp[i][k][1]為dp[i-1][k][1]再加上nums[i]的最大強度。

```
do not pick nums[i]:
=> dp[i][k][0]=max(dp[i-1][k][0], dp[i-1][k][1]);

do pick nums[i]:
1, nums[i] as k-th subarray
=> dp[i][k][1]=max(dp[i-1][k-1][0], dp[i-1][k-1][1])+pow(-1, k+1)*nums[i]*k;

2, nums[i] merge with k-th subarray
=> dp[i][k][1]=dp[i-1][k][1]+pow(-1, k+1)*nums[i]*k;    
```

- 設定邊界條件及dp數組初始值。

不一定要全選所有元素，因此前i個元素分成0份最大強度為0作為邊界條件，要求最大值，dp初值給最小值。

```
for (int i=0; i<=n; i++)
  dp[i][0]=0;
```

- 得出結論

有最後一個維度處理nums[i]是否在第k個子數組的狀態，因此前n個元素分成K個子數組的最大強度在dp[n][K][0]跟dp[n][K][1]中挑一個最大值就行。
