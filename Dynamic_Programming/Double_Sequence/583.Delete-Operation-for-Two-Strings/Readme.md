# 583.Delete-Operation-for-Two-Strings

- 觀察在word1[i]跟word2[j]的位置要如何做選擇？

```
X X X X X X i
X X X X X j
```

- 思考需要哪些狀態？

要看兩元素是否相等決定要不要刪除該元素，狀態需要i、j分別指向word1、word2。

- 定義dp數組含義。

照抄題目要求的目標。

```
dp[i][j]: the minimum number of steps required to make word1[1:i] and word2[1:j] the same.
```

- 推導狀態轉移方程。

元素相等則跳過不做操作，元素不等試著刪除word1[i]或word2[j]看哪個所需次數最小。

```
if (word1[i]==word2[j]) dp[i][j]=dp[i-1][j-1];
else dp[i][j]=min(dp[i-1][j], dp[i][j-1])+1;
```

- 設定邊界條件及dp數組初值。

其中一個序列被刪到為空，需視另一序列剩餘的元素個數全數刪除。

```
X X X X X i

dp[i][0]=i

X X j
dp[0][j]=j
```
