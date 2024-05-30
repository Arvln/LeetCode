# 1035.Uncrossed-Lines

- 考慮在nums1[i]跟nums2[j]的位置要如何做選擇?

通常是看nums1[i]跟nums2[j]是否相等，相等可以將nums1[i]跟nums2[j]連線。若不相等則分別去除nums1[i]跟nums2[j]並在剩餘序列中取最大連線數。

```
X X X X X X X i
Y Y Y Y Y j
```

- 思考需要哪些狀態？

狀態需要i、j分別指向在nums1、nums2中位置。

- 定義dp數組含義。

照抄題目要求的目標。

```
dp[i][j]: the maximum number of connecting lines between nums1[1:i] and nums2[1:j].
```

- 推導狀態轉移方程。

元素相等則連線，元素不等試著跳過nums1[i]或nums2[j]看剩餘序列中哪個最大連線數更大。

```
if (nums1[i]==nums2[j]) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
```

- 設定邊界條件及dp數組初值。

其中一個序列被縮減為空，跟另一序列無法產生連線。要求最大值dp數組初始值給最小值。

```
X X X X X i
-

dp[i][0]=0

-
Y Y Y j
dp[0][j]=0
```

- 得出結論。

nums1[1:m]跟num2[1:n]之間能產生最大連線數為dp[m][n]。
