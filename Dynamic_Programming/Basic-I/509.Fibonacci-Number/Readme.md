# 509.Fibonacci-Number

經典動態規劃題目之一，依照動規套路來解題。

- 思考對為第i個元素來說，應該怎麼做選擇？

```
X X X X X [X X] i
```

- 根據函數定義第i個元素為第i-1和第i-2個元素之和，因此需要的狀態是當前元素的位置i。

- 確認狀態後可以定義dp數組。

```
dp[i]: the i-th number of the Fibonacci sequence.
```

- 狀態轉移方程就照抄函數定義。

```
dp[i]=dp[i-1]+dp[i-2];
```

- 設定base case及dp數組初始值。

```
dp[0]=0;
dp[1]=1;
```
