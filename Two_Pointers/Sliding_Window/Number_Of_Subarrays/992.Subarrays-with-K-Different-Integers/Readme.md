# 992.Subarrays-with-K-Different-Integers

查子串或子數組，思路往滑動窗口上靠，求恰好有 k 個不同整數的子數組數目，正難則反，換個想法是最多有 k 個不同整數的子數組數目減去最多有 k-1 個不同整數的子數組數目

```
at_most_k(nums, k)-at_most_k(nums, k-1);
```

最後實作最多有 k 個不同整數的子數組數目，需要一個數組或哈希表紀錄窗口內不同整數的個數，當數字第一次進到窗口時更新窗口內不同整數的總數，當窗口內不同整數的總數大於 k 時右移左指針直到窗口內不同整數數量小於等於 k 為止

```
while (left<right&&cur_amount>k)
{
  if (records[nums[left]]==1) cur_amount-=1;
  records[nums[left]]-=1;
  left++;
}
```
