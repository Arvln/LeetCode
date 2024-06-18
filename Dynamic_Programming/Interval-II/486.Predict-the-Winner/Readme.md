# 486.Predict-the-Winner

跟 #877 思路一模一樣，都是從左右兩側隨便挑掉一顆石頭，觀察先手玩家能從剩餘石頭中多取幾顆石頭。

- 可以做哪些選擇？

```
[i X X X X X X X j]
```

先手玩家在[i:j]可比對手多得幾分取決於nums[i]-後手玩家在[i+1:j]可比對手多得幾分跟nums[j]-後手玩家在[i:j-1]可比對手多得幾分，兩個挑一個最大值。

- 思考需要哪些狀態？

標示區間範圍的最左端i及最右端j。

- 定義dp數組含義。

```
dp[i][j]: the maximum difference of score player1 can reach in nums[i:j].
```

- 推導狀態轉移方程。

```
dp[i][j]=max(nums[j]-dp[i][j-1], nums[i]-dp[i+1][j]);
```

- 設定邊界條件及dp初始值。

當i大於j時不是可能區間，遍歷區間長度從2開始，確保dp值不會越界。區間長度為1當作邊界條件額外設定。狀態會從小區間往大區間轉移不需設置dp數組初始值。

```
for (int i=0; i<n; i++)
  dp[i][i]=nums[i];
```

- 得出結論。

player1在完整區間內可比player2多得dp[0][n-1]分，檢查分數差大於等於0即為獲勝。
