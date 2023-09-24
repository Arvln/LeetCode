# 1248.Count-Number-of-Nice-Subarrays

查子串或子數組，思路往滑動窗口上靠，求恰好有 k 個奇數的子數組數目，換個想法是最多有 k 個奇數的子數組數目減去最多有 k-1 個奇數的子數組數目

```
at_most_k(nums, k)-at_most_k(nums, k-1);
```

最後實作最多有 k 個奇數的子數組數目，當奇數進到窗口時增加窗口內奇數的總數，當窗口內奇數的總數大於 k 時右移左指針直到窗口內奇數數量小於等於 k 為止

```
while (left<right&&cur_amount>k)
{
  if (nums[left]&1) cur_amount-=1;
  left++;
}
```
