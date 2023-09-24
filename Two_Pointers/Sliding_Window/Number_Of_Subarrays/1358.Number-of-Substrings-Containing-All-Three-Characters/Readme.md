# 1358.Number-of-Substrings-Containing-All-Three-Characters

查子串或子數組，思路往滑動窗口上靠，求 3 個字符都出現的子數組數目，換個想法是求最多出現 3 個字符的子數組數目減去最多出現 2 個字符的子數組數目

```
at_most_k(nums, 3)-at_most_k(nums, 2);
```

最後實作最多出現 k 個字符的子數組數目，用一個數組或哈希表紀錄窗口內各種字符數目，超過 k 個字符再右移左指針直到窗口內不同字符小於等於 k 個

```
while (left<right&&cur_amount>k)
{
  if (records[nums[left]]==1) cur_amount-=1;
  records[nums[left]]-=1;
  left++;
}
```
