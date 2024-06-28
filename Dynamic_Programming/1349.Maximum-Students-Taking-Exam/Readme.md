# 1349.Maximum-Students-Taking-Exam

思路跟 #514 有點相似，當前狀態只跟前一輪有關，需要額外開一個維度紀錄狀態訊息。#514 是要知道字符位置訊息，這裡則是要知道整排學生的座位分布。同一字符可能對應不同位置可以用哈希表來輔助遍歷所有可能位置，學生的座位分布可以通過狀態壓縮成二進制數字表示。每一排座位最多8個強烈暗示可用狀態壓縮dp的思路。

- 對於第i列可以做哪些選擇？

```
X X X X X [X] i
```

第i-1列最大有效座位分布的學生數加上第i列有效座位分布的學生數有機會更新第i列最大有效座位分布的學生數。

- 思考需要哪些狀態？

紀錄當前列數訊息i跟學生座位分布狀態p。

- 定義dp數組含義。

```
dp[i][p]: the maximum number of students that can take the exam together without any cheating being possible in i-th row with pattern p.
```

- 推導狀態轉移方程。

```
dp[i][p]= max{ dp[i][p], dp[i-1][p']+count(p, i) } for all p'
```

- 設定邊界條件及dp初始值。

第1列的學生座位分布狀態只要兩旁不坐人就行，沒有前一列需要考慮。要求最大值dp數組初始值給0。

```
for (int p=0; p<N; p++)
  if (rowValid(p, 0)) dp[p]=count(p, 0);
```

- 得出結論。

最大有效座位分布的學生數為最後一列有效座位分布的學生數中取最大值。

```
for (int p=0; p<N; p++)
  if (rowValid(p, m-1)) ret=max(ret, dp[p]);
```
