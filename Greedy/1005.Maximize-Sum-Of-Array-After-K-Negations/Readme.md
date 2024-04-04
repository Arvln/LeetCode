# 1005.Maximize-Sum-Of-Array-After-K-Negations

給你一個數組跟可以翻轉數組中數字正負號k次權力，求數組最大可能總和。先分情況討論，假設數組中負數個數大於等於k，要把從最小負數開始的負號依序翻成正號。負數個數小於k，先把所有負號翻成正數再看剩餘的k，假設k剩餘數為偶數，因為可以互相抵銷不影響結果，k剩餘數為奇數，可以把絕對值最小的數翻為負號。要依序翻轉負數先排個序，從最小負數開始翻最划算。

```
sort(nums.begin(), nums.end());
```

根據分析最後需要判斷k剩餘數，是奇數代表全部負號都可翻成正號，需要扣除值最小的數，是偶數不用處理。

```
if (k%2==0) return sum;
else return sum-2*minVal;
```

按照結果迴圈要算總和及最小值，因為已經排過序，只要數字小於零就翻成正數，直到把k用光。

```
int sum=0, minVal=100;
for (int num : nums)
{
    if (num<0&&k>0)
    {
        k--;
        num*=-1;
    }
    minVal=min(minVal, num);
    sum+=num;
}
```
