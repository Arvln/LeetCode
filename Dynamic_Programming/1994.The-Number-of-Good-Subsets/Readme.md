# 1994.The-Number-of-Good-Subsets

根據提示每個數字根據提示每個數字最大是30，1到30中有10個質數，所有好的子集可以用10個bit表示選中的質因數狀態。

- 對於第i個數字可以做哪些選擇？

```
X X X X X [X] i
```

前i-1個數字構成的好子集數量乘以第i個數字總數可以累加到前i個數字構成的好子集數量上。

- 思考需要哪些狀態？

紀錄當前數字位置訊息i跟質因數分布狀態p。

- 定義dp數組含義。

```
dp[i][p]: the number of different good subsets in i-th num with pattern p.
```

- 推導狀態轉移方程。

```
if ((p&mask)==mask) dp[i][p]+=dp[i-1][p-mask]*count[num];

dp[{2,3,5,7}]+=pre_dp[{2,3,5}]*count[7];
```

- 設定邊界條件及dp初始值。

空子集算一個有效子集數當作邊界條件。為方便做加法運算dp數組初始值給0。

```
dp[0]=1;
```

- 得出結論。

所有好子集個數為所有質因數分布狀態的加總，再處理所有數字1，每個數字1可以取或不取。

```
for (int p=0; p<N; p++)
  ret+=dp[p];
for (int i=0; i<count[1]; i++)
  ret*=2;
```
