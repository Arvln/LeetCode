# 312.Burst-Balloons

- 可以做哪些選擇？

```
[i X X X k X X X j]
```

在[i:j]中隨便射爆一顆氣球k，[i:j]最大收益取決於[i:k-1]最大收益加上[k+1:j]最大收益再加上射爆氣球k的收益為nums[i-1]*nums[k]*nums[j+1]。

- 思考需要哪些狀態？

標示區間範圍的最左端i及最右端j。

- 定義dp數組含義。

```
dp[i][j]: the maximum coins you can collect by bursting the balloons in nums[i:j].
```

- 推導狀態轉移方程。

```
dp[i][j]=max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[k]*nums[i-1]*nums[j+1]);
```

- 設定邊界條件及dp初始值。

當i大於j時不是可能區間，收益為0，因此dp數組初始值設為0。當區間是完整區間時，nums[i-1]跟nums[j+1]會在界外需設為1。

```
nums.insert(nums.begin(), 1);
nums.push_back(1);
vector<vector<int>>dp(n+2, vector<int>(n+2, 0));
```

- 得出結論。

完整區間內射爆所有氣球的最大收益為dp[1][n]。
