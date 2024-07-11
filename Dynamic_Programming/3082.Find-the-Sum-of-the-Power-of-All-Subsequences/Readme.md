# 3082.Find-the-Sum-of-the-Power-of-All-Subsequences

計算有多少子序列可以湊滿目標和是常規背包問題。

- 對於第i個物品如何做選擇？

```
X X X X X i
```

可以選擇取或不取該元素以構造目標和。

- 思考需要哪些狀態？

01背包問題需要代表物品位置的狀態i、目標和s。

- 定義dp數組含義。

```
dp[i][s]: the number of subsequences in nums[1:i] with their sum equal to s.
```

- 推導狀態轉移方程。

```
dp[i][s]=dp[i-1][s]+dp[i-1][s-nums[i]];
```

- 設定邊界條件及dp初始值。

0個元素湊成目標和為0是一種方法當作初始條件，dp初始值設為0方便累加。

```
dp[0][0]=1;
```

- 得出結論。

前n個元素構造目標和為s的方法數為dp[n][s]。

- 分析子序列跟所求目標的關聯。

題目要求的就是這些子序列和為目標和的序列有多少個超級序列。長度為m的子序列可以構成2^(n-m)個長度為n的超級序列。

```
X Y X Y Y X Y X -> n
Y Y Y Y -> m
super sequence -> 2^(n-m)
```

因此需要再多加上長度這個維度方便後續計算超級序列的個數，重新定義dp數組含義。

```
dp[i][s][l]: the number of subsequences in nums[1:i] with their sum equal to s and have l length.
```

求出各長度對應的子序列個數後再按長度累加子序列所能對應的超級序列個數就行。
