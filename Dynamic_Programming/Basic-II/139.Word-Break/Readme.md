# 139.Word-Break

字串字典中每個字串前綴可能高度重合，將數組轉化成字典樹可提高查詢效率。

- 思考對於第i個元素可以做哪些選擇？

```
X X X [j X X X i]
```

當最後一份字串出現在字典中且前j-1個字符組成的字串可被字典中字串拼接出來則前i個字符組成的字串也可被字典中字串拼接出來。

- 思考需要哪些狀態？

字符位置i。

- 定義dp數組含義。

```
dp[i]: if s[1:i] can be segmented into a space-separated sequence of one or more dictionary words.
```

- 推出狀態轉移方程。

```
if (dp[j-1]==true&&s[j:i] in dict) dp[i]=true;
```

- 設定邊界條件及dp初始值。

所有字符都被匹配當作邊界條件，dp數組初始值設為false。

```
dp[0]=true;
```

- 得出結論。

目標字串是否可被字典中字串拼接出來取決於dp[n]。
