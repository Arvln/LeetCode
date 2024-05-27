# 673.Number-of-Longest-Increasing-Subsequence

跟 #300 思路差不多，在求LIS基礎上多求一個個數。

- 思考對於第i個元素可以做哪些選擇？

```
X X X j X X X i
```

當以nums[j]結尾的最長遞增子序列長度加1大於以nums[i]結尾的最長遞增子序列長度，代表是一個可以更新的候選，以nums[i]結尾的最長遞增子序列個數完全繼承自以nums[j]結尾的最長遞增子序列個數。當以nums[j]結尾的最長遞增子序列長度加1等於以nums[i]結尾的最長遞增子序列長度，以nums[i]結尾的最長遞增子序列個數需再加上以nums[j]結尾的最長遞增子序列個數。

- 思考需要哪些狀態？

子序列結尾數字位置i。

- 定義dp數組含義。

```
len[i]: the length of longest increasing subsequences ending at nums[i].
count[i]: the number of longest increasing subsequences ending at nums[i].
```

- 推出狀態轉移方程。

```
if (len[j]+1>len[i])
{
  len[i]=len[j]+1;
  count[i]=count[j];
}
else if (len[j]+1==len[i]) count[i]+=count[j];
```

- 設定邊界條件及dp初始值。

以任意值為結尾的子序列長度及個數最少是1。

```
vector<int>len(n, 1);
vector<int>count(n, 1);
```

- 得出結論。

最長遞增子序列可能以任意數字結尾且可能存在數個，需掃一遍所有dp值。

```
int maxLen=0, ret=0;
for (int i=0; i<n; i++)
    if (maxLen<len[i])
    {
        maxLen=len[i];
        ret=count[i];
    }
    else if (maxLen==len[i]) ret+=count[i];
```
