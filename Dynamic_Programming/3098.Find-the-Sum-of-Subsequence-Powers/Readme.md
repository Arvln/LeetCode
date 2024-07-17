# 3098.Find-the-Sum-of-Subsequence-Powers

數組長度最長為50，總共有2^50種子序列，這個數非常大不可能先枚舉出所有子序列再計算。要求的是所有子序列中最小的差之和，可以先對數組排序再用N^2枚舉出所有最小的差可能的數字組合，再計算該組合可能對應哪些子序列，再做加總就行。

```
diff = b-a
X X X X X [a X b] X X X X X 

sort(nums.begin(), nums.end());
for (int a=0; a<n; a++)
  for (int b=a+1; b<n; b++)
  {
    int diff=nums[b]-nums[a];
    ret+=count(nums, a, b, diff, k);
  }
```

接著從[0:a]及[b:n-1]兩側區間中元素挑k個。子序列中可能有多個數間差值相等，這種子序列只會被計入最小的差是{1,2}的首個出現的數字組合中，不會被重複計入{2,3}或{3,4}的數字組合中。因此[0:a]的元素彼此差值要嚴格大於diff且[b:n-1]的元素彼此差值要大於等於diff。

```
X X X [1 X 2] X X 3 X X 4 X X 
```

要求以nums[a]結尾且長度為k對應的子序列個數跟以nums[b]開頭且長度為k對應的子序列個數，可以用N^3的解法求出。

- 思考對於第i個元素可以做哪些選擇？

```
X [k X X X i] X a
b X [i X X X k] X
```

往前找到讓nums[i]-nums[k]>diff的元素k，此時以nums[k]結尾構成長度為len-1的所有有效子序列可以轉移到以nums[i]結尾構成長度為len的所有有效子序列上。同理，往後找到讓nums[k]-nums[i]>=diff的元素k，此時以nums[k]開頭構成長度為len-1的所有有效子序列可以轉移到以nums[i]開頭構成長度為len的所有有效子序列上。

- 思考需要哪些狀態？

元素位置i跟長度k。

- 定義dp數組含義。

```
front[i][j]: the number of subsequence ending at nums[i] with length j and diff>d.
back[i][j]: the number of subsequence starting at nums[i] with length j and diff>=d.
```

- 推出狀態轉移方程。

```
if (nums[i]-nums[k]>k) front[i][j]+=front[k][j-1];
if (nums[k]-nums[i]>=k) back[i][j]+=back[k][j-1];
```

- 設定邊界條件及dp初始值。

長度為1的子序列個數就是1當作初始條件，dp數組初始值給0方便做加法運算。

```
for (int i=0; i<n; i++)
{
  front[i][1]=1;
  back[i][1]=1;
}
```

- 得出結論。

前後元素合併長度為len的子序列總數，只要窮舉所有可能長度對應的子序列個數再相乘就行。最後將有效子序列總數乘上最小的差值就是所求。

```
for (int l=0; l<len; l++)
  count+=dp[a][l]*dp[b][len-l];
```
