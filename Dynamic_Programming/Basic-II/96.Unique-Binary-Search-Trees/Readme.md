# 96.Unique-Binary-Search-Trees

給n顆節點要求總共可以構建出幾種二叉搜索樹結構。通過觀察可知數量多的節點是依賴在數量少的節點所能產生的結構上，因此可用動態規劃求解。

- 需要哪些狀態？

需要的狀態就是節點數。

- 定義dp數組含義

照抄題目要求的。

```
dp[i]: the number of structurally unique BST's (binary search trees) which has exactly i nodes of unique values from 1 to i.
```

- 推導狀態轉移方程

要求i個節點可以構成的BST結構總數，可以把前面任意數j抓出來當作根節點，看看總共能產生多少結構，再將所有結構數加總就行。以j為根節點，j-1個節點能產生的左子樹數量乘上i-j個節點能產生的右子樹數量就是以j為根可產生的樹結構數。

```
[1 X X] j [X X X i]

dp[i]+=dp[j-1]*dp[i-j];
```

- 設定邊界條件及dp數組初始值。

邊界條件相當簡單，沒有任何節點時，空節點可產生一棵樹，dp初始值給0方便做累加。

```
dp[0]=1;
```
