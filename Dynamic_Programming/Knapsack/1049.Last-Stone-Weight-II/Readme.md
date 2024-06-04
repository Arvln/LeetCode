# 1049.Last-Stone-Weight-II

石頭相消的結果可表示為數學式。

```
||a - b| - c| - |d - e|
```

要將絕對值去除，可在式子前加正負號，因此在每個數前加正負號的所有運算式中，計算出最小和就是石頭相消最小可能重量。

```
+/- a +/- b +/- c +/- d +/- e
```

再轉成類似 #494 的想法按照背包思路來解就行。

- 對於第i顆石頭如何做選擇？

石頭可以增加或減少總重。

- 思考需要哪些狀態？

每顆石頭只能挑一次，為01背包問題，需要開表示石頭位置的i跟容量weight兩個維度。

- 定義dp數組含義。

```
dp[i][weight]: the smallest possible weight of the left stone in i-th stone.
```

- 推導狀態轉移方程。

```
if (dp[i-1][weight-stones[i]]==true) dp[i][weight]=true;
if (dp[i-1][weight-stones[i]]==true) dp[i][weight]=true;
```

- 設定邊界條件及dp初始值。

有0塊可以湊出總重量為0當作邊界條件、dp數組初始值設為false。

```
dp[0][0]=0;
```

- 得出結論。

有n塊石頭相消可以湊出最小重量為最接近0可以使dp[n][weight]為true的總重量。
