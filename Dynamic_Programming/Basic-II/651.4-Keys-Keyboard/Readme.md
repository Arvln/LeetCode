# 651.4-Keys-Keyboard

- 思考對於第i次按鍵可以做哪些選擇？

```
X X X X X X X i
```

可以直接按A，從第i-1次按鍵打印數轉移過來。也可以選擇複製鍵，會從第i-2-1,i-2-2,..等所有次數轉移過來，取決於連續按幾次複製鍵。

- 思考需要哪些狀態？

按鍵次數i。

- 定義dp數組含義。

```
dp[i]: the maximum numbers of 'A' you can print on screen by pressing the keyboard for i times.
```

- 推出狀態轉移方程。

```
dp[i]=dp[i-1]+1;
for (int j=1; i-2-j>0; j++)
  dp[i]=max(dp[i], dp[i-2-j]*(j+1));
```

- 設定邊界條件及dp初始值。

按0次按鍵最多可打印出0個A當作邊界條件，初始值可以給按下按鍵A能打印的最大數量。

```
dp[0]=0;
```

- 得出結論。

按n次能打印的最大數量為dp[n]。
