# 3202.Find-the-Maximum-Length-of-Valid-Subsequence-II

- 思考對於第i個元素可以做哪些選擇？

```
X X X j X X X i
```

觀察題意可發現nums[i]跟nums[j]之間關係可用數學式表達。

```
(nums[i]+nums[j])%k==mod
nums[j]%k==(mod-nums[i]%k+k)%k
```

移項後發現要求nums[j]對k取餘數等於mod-nums[i]%k的最大子序列長度再加上nums[i]有機會更新nums[i]結尾餘數為mod的最大子序列長度。

- 思考需要哪些狀態？

元素位置i跟餘數m。

- 定義dp數組含義。

```
dp[i][m]: the length of the longest valid subsequence of nums[0:i] with mod equal to m.
```

- 推出狀態轉移方程。

```
int mod=(mod-nums[i]%k+k)%k;
int j=modToIndex[mod];

dp[i][m]=dp[j][m]+1;
```

- 設定邊界條件及dp初始值。

前面沒有滿足條件的j存在時，子序列長度為1。要算長度dp數組初始值給0。

```
int j=modToIndex[mod];
if (j==-1) dp[i][m]=1;
```

- 得出結論。

不確定最長子序列會在哪結尾、餘數為多少，因此對所有結尾位置及餘數的子序列長度取最大值。
