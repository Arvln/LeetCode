# 91.Decode-Ways

- 思考在第i位如何做選擇？

```
X X X X X X X i
```

思考以s[i]結尾的字串最後一個字母怎麼解碼。假設s[i]可以單獨解碼，以s[i]結尾的字串解碼方法數可以加上以s[i-1]結尾的字串解碼方法數。假設s[i-1:i]可以解碼，以s[i]結尾的字串解碼方法數可以加上以s[i-2]結尾的字串解碼方法數。

- 思考需要哪些狀態？

只需要位置i這項訊息。

- 明確dp數組的含義。

```
dp[i]: the number of ways to decode s[1:i].
```

- 推導狀態轉移方程。

```
if (s[i]>'0') dp[i]+=dp[i-1];
if (i>=2&&s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6')) dp[i]+=dp[i-2];
```

- 設定邊界條件及dp初始值。

長度為0的字串也代表一種解法方式，dp數組初始值直接設為0方便做加法運算。

```
dp[0]=1;
```

- 得出結論。

以s[n]結尾的字串解碼方法數dp[n]。
