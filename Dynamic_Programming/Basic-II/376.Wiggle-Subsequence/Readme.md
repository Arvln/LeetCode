# 376.Wiggle-Subsequence

- 思考對於第i個元素可以做哪些選擇？

```
X X X j X X X i
```

第i個元素結尾的擺動序列可能是上升或下降結尾，可分情況討論，當是上升結尾時，前面所有結尾元素小於i且是下降結尾的序列最大長度都有機會更新上升結尾的序列最大長度。當是下降結尾時，前面所有結尾元素大於i且是上升結尾的序列最大長度都有機會更新下降結尾的序列最大長度。

- 思考需要哪些狀態？

結尾元素位置i及上升或下降狀態status。

- 定義dp數組含義。

```
dp[i][status]: the length of the longest wiggle subsequence of nums ending at i with positive / negative diff.
```

結尾只可能是上升或下降，可將dp降維成兩個數組。

```
pos[i]: the length of the longest wiggle subsequence of nums ending at i with positive diff.
neg[i]: the length of the longest wiggle subsequence of nums ending at i with negative diff.
```

- 推出狀態轉移方程。

```
if (nums[i]>nums[j]) pos[i]=max(pos[i], neg[j]+1);
else if (nums[i]<nums[j]) neg[i]=max(neg[i], pos[j]+1);
```

- 設定邊界條件及dp初始值。

以任意元素結尾的擺動序列長度最少為1，因此dp初始值給1。

```
vector<int>pos(n, 1);
vector<int>neg(n, 1);
```

- 得出結論。

最長擺動序列可能以任意元素、上升或下降狀態結尾。

```
max{ pos[i], neg[i] } for i=0,1,.. ,n-1
```
