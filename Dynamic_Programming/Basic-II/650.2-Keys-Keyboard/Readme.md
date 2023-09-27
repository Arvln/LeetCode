# 650.2-Keys-Keyboard

求最值得問題思路往 dp 靠，直接把要求的結果當作 dp 數組的定義

```
dp[i]:  the minimum number of operations to get the character 'A' exactly i times
```

要湊到 i 個'A'可能是從所有可以整除 i 的數字作為長度的'A'字串複製貼上而來，比如要湊滿 6 個'A'有下面 3 種可能性，從中取最小操作次數即可

```
AAA AAA -> copy all*1 + paste*1
AA AA AA -> copy all*1 + paste*2
A A A A A A -> copy all*1 + paste*5
```

推導狀態轉移方程

```
int k=i/j;
dp[i]=max(dp[i], dp[k]+1+j-1);
```

由於複製的字串長度越長，貼上所需次數就越小，可以此做優化，第一個找到可整除 i 的 j 就是最長的可整除 i 的字串，後面都不必再嘗試，可直接跳出循環

```
for (int i=1; i<=n; i++)
  for (int j=2; j<=i; j++)
  {
    if (i%j!=0) continue;
    int k=i/j;
    dp[i]=max(dp[i], dp[k]+1+j-1);
    break;
  }
```
