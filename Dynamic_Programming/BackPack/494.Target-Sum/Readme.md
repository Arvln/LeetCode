# 494.Target-Sum

一堆元素中做挑選滿足目標和，可以當作背包問題，對於第 i 個元素思考一個 dp 數組的定義，直接把要求的結果拿來用

```
dp[i][s] => the number of different expressions that you can build, which evaluates to s ending at nums[i]
```

對於第 i 個元素要湊齊 s 有兩種可能

```
I. 第i-1個元素已湊齊s-nums[i]，第i個元素選擇加號
II. 第i-1個元素已湊齊s+nums[i]，第i個元素選擇減號
```

推出狀態轉移方程

```
dp[i][s]=dp[i-1][s-nums[i]]+dp[i-1][s+nums[i]];
```

處理越界問題及初始值，依據提示目標和介於-1000 到 1000 之間，前 i-1 個元素計算結果也要滿足要求，負數索引向右邊移為正的索引

```
int offset=1000;
dp[0][0+offset]=1;
for (int i=1; i<n; i++)
  for (int s=-1000; s<=1000; s++)
  {
    if (s-nums[i]>=-1000)
      dp[i][s+offset]+=dp[i-1][s-nums[i]+offset];

    if (s+nums[i]<=1000)
      dp[i][s+offset]+=dp[i-1][s+nums[i]+offset];
  }
```

返回第 n-1 個元素和為 target 的 dp 值

dp[n][target+offset]
