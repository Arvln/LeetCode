# 1659.Maximize-Grid-Happiness

根據提示發現矩陣的長寬非常小，暗示可以用狀態壓縮dp的思路，每列最多3^5可以枚舉出所有人員分布的狀態，需要另開一個維度紀錄。對內向人及外向人的人數設有上限，需要各開一個維度紀錄。

- 對於第i列可以做哪些選擇？

```
X X X X X [X] i
```

第i-1列內向人跟外向人數上限分別為x-p跟y-q可得的最大幸福感加上該列內向人跟外向人數分別為p跟q可得幸福感有機會更新第i列內向人跟外向人數上限分別為x跟y可得的最大幸福感。

- 思考需要哪些狀態？

紀錄當前列數訊息i、內向人數上限x、外向人數上限y跟人員分布的狀態p。

- 定義dp數組含義。

```
dp[i][x][y][p]: the maximum possible grid happiness in i-th row have x introverts and y extroverts with pattern p.
```

- 推導狀態轉移方程。

```
dp[i][x][y][p]= max{ dp[i][x][y][p], dp[i-1][x-p][y-q][p']+happiness(p, p') } for all p'
```

- 設定邊界條件及dp初始值。

將所有列數右移避免越界搭配第0列內向人跟外向人數上限為0且沒有人員的狀態當作邊界條件。要求最大值dp數組初始值給最小值。

```
dp[0][0][0][0]=0;
```

- 得出結論。

最大幸福感為最後一列中所有可能的內向人數上限x、外向人數上限y、人員分布p中取最大值。

```
for (int x=0; x<=introvertsCount; x++)
  for (int y=0; y<=extrovertsCount; y++)
    for (int p=0; p<N; p++)
      ret=max(ret, dp[m][i][j][p]);
```
