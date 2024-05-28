# 956.Tallest-Billboard

要湊到兩邊棒子長度相等，直觀想法是將左右兩邊棒子長度都定為dp數組的一個維度。因此可以窮舉出所有可能情況，不過複雜度超過1e6，算法將會TLE。

```
dp[left][right]: wheather the billboard will have left and right steel supports on each side.

for (int i=0; i<N; i++)
{
  int l=rods[i];

  for (int left=0; left<=2500; left++)
    for (int right=0; right<=2500; right++)
      if (dp[left][right]==true)
        {
            dp[left+l][right]=true;
            dp[left][right+l]=true;

            if (left+l==right) ret=max(ret, left+l);
            if (left==right+l) ret=max(ret, right+l);
        }
}
```

兩邊長度相等表示兩根棒子長度差為0，在此基礎上可以轉化為01背包問題，思路跟 #494 差不多。

- 對於第i跟棒子如何做選擇？

可以把棒子插在左邊或右邊。

- 思考需要哪些狀態？

01背包問題需要代表物品的位置i及容量diff。

- 定義dp數組含義

```
dp[diff]: the largest height of left steel with diff.
```

- 推導狀態轉移方程。

```
dp[diff+l]=max(dp[diff+l], pre_dp[diff]+l);
dp[diff-l]=max(dp[diff-l], pre_dp[diff]);
```

特別注意diff取值範圍[-5000, 5000]，向右取偏移量5000讓取值範圍轉為[0,10000]避免數組索引越界，再補上條件判斷防止處理棒子長度時越界。

```
int offset=5000;
for (int diff=-offset; diff<=offset; diff++)
{
  if (diff+l<=offset)
    dp[diff+l+offset]=max(dp[diff+l+offset], pre_dp[diff+offset]+l);
  if (diff-l>=-offset)
    dp[diff-l+offset]=max(dp[diff-l+offset], pre_dp[diff+offset]);
}
```

- 設定邊界條件及dp初始值。

當左右兩邊都沒有棒子時，左邊棒子最長長度為0。要求最大值dp數組初始值給最小值。

```
dp[0+offset]=0;
```

- 得出結論。

兩邊棒子長度差為0，左邊棒子長度最長為dp[0+offset]。
