# 718.Maximum-Length-of-Repeated-Subarray

給兩個數組要求最長共享子數組的長度，給兩個序列可以直接套雙序列dp思路。

- 觀察在nums1[i]跟nums2[j]的位置要如何做選擇？

一般都是看nums1[i]和nums2[j]是否相等，相等的話可以取這個數字做為公共子數組的一部分，不相等則不取。

```
X X X X X X i
Y Y Y Y Y j
```

- 接著思考需要哪些狀態？

推導狀態需要nums1當前元素的位置i和nums2當前元素的位置j。

- 明確狀態後可以定義dp數組含義，照抄題目要求的目標。

```
dp[i][j]: the maximum length of a subarray that appears in both arrays ending at nums1[i] and nums2[j].
```

- 推導狀態轉移方程。

當兩數相等時，以nums1[i]和nums2[j]結尾的最長公共子數組長度等於以nums1[i-1]和nums2[j-1]結尾的公共最長子數組長度+當前數字nums1[i]或nums2[j]。若兩數不相等，代表以nums1[i]和nums2[j]結尾的最長公共子數組長度必為0。

```
if (nums1[i]==nums2[j]) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=0;
```

- 設定邊界條件及dp數組初始值。

邊界條件考慮其中一序列為空。題目要求最大值，因此0不影響判斷，方便起見把數組初始值都置為0。

```
X X X X X i
-

dp[i][0]=0;

-
Y Y Y j

dp[0][j]=0;
```

最長公共子數組可能以任何nums1[i]和nums2[j]結尾，所以要取所有dp[i][j]中的最大值。
