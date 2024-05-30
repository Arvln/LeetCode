# 983.Minimum-Cost-For-Tickets

- 思考對於第i個元素可以做哪些選擇？

```
X X X [j X X X i]
```

當days[i]跟days[j]差距在車票使用期限內，可嘗試購買該車票最小化總車資。

- 思考需要哪些狀態？

日期位置i。

- 定義dp數組含義。

```
dp[i]: the minimum number of dollars you need to travel every day in the given list of days[1:i].
```

- 推出狀態轉移方程。

```
int diff=days[i]-days[j];

if (diff<1) dp[i]=min(dp[i], dp[j-1]+costs[0]);
if (diff<7) dp[i]=min(dp[i], dp[j-1]+costs[1]);
if (diff<30) dp[i]=min(dp[i], dp[j-1]+costs[2]);
```

- 設定邊界條件及dp初始值。

不用覆蓋任何日期所需車資為0當作邊界條件，要求最小值dp數組初始值設為最大值。

```
dp[0]=0;
```

- 得出結論。

覆蓋days[1:n]的最小車資為dp[n]。
