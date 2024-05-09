# 931.Minimum-Falling-Path-Sum

題目敘述很明顯可以看出每一列的結果只跟前一列有關，暗示要用dp來做。

- 思考在第i列可以做哪些選擇?

某格子為終點的路徑只可能從左上、正上、右上格子其中一條走下來。

- 思考需要哪些狀態變量?

需要i、j指定格子的座標。

- 定義dp數組含義。

```
dp[i][j]: the minimum sum of any falling path through matrix 
ending at matrix[i][j].
```

- 推導狀態轉移方程。

```
dp[i][j]=min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])+matrix[i][j];
```

- 設定邊界條件及dp數組初始值。

i從0開始遍歷的話，i-1會越界，因此改成從1開始遍歷搭配定義i=0時的路徑和作為邊界條件。

```
for (int j=0; j<n; j++)
  dp[0][j]=matrix[0][j];
```

j從0到n-1的遍歷過程一樣會越界，加上條件判斷避免越界。

- 得出結論

從上到下最小路徑和可能以{m-1, 0},{m-1, 1},...,{m-1, n-1}其中任意的格子結尾。

```
min { dp[m-1][j] } for j=0,1,..,n-1
```
