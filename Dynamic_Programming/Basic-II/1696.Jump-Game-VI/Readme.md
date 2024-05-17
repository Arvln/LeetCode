# 1696.Jump-Game-VI

- 思考對於第i個元素可以做哪些選擇？

```
X X [i-k X X X] i
```

到達第i位置的最大得分可從到達[i-k:i-1]範圍內的最大得分加上第i位的分數得出。

- 思考需要哪些狀態？

最終抵達的位置i。

- 定義dp數組含義。

```
dp[i]: the maximum score you can get to reach nums[i].
```

- 推出狀態轉移方程。

```
dp[i]=max(dp[i], dp[j]+nums[i]) for j=i-k, i-k+1, .., i-1
```

- 如何搜出[i-k:i-1]的最大值？

最直覺的方法就是暴力搜一遍，複雜度為n^2。看一下數據量n為1e5會TLE。

```
for (int i=0; i<n; i++)
    for (int j=max(0, i-k); j<i; j++)
        dp[i]=max(dp[i], dp[j]+nums[i]);
```

回想 #239 求滑窗最大值的思路，可維護一個單調遞減隊列求出前k個dp值中的最大值，複雜度降為n。

```
for (int i=0; i<n; i++)
{
    while (!dq.empty()&&i-dq.front()>k)
        dq.pop_front();
    
    if (!dq.empty()) dp[i]=max(dp[i], dp[dq.front()]+nums[i]);

    while (!dq.empty()&&dp[dq.back()]<=dp[i])
        dq.pop_back();
    dq.push_back(i);
}
```

- 設定邊界條件及dp初始值。

到達索引0位置的得分當作邊界條件，要求最大值dp數組初始值給最小值。

```
dp[0]=nums[0];
```

- 得出結論。

到達索引n-1的最大得分為dp[n-1]。
