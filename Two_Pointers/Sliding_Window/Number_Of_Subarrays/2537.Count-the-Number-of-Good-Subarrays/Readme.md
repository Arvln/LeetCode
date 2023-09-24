# 2537.Count-the-Number-of-Good-Subarrays

查子串或子數組，思路往滑動窗口上靠，求至少 k 對符合條件的子數組數目，換個想法是所有子數組數目減去最多 k-1 對符合條件的子數組數目，第 n 個元素可以增加 n 個子數組，所有子數組數目就是等差級數和

```
(n+1)*n/2-at_most_k(nums, k-1);
```

左右指針右移可增加或減少的滿足 i < j 且 nums[i]==nums[j]的對數跟窗口內不同元素的個數有關，用一個哈希表紀錄窗口內各元素個數，假設窗口內有 3 個 1，右指針右移加入 1 時，新加入的 1 可以跟原本 3 個 1 各自組成一個新的配對，共可增加 3 對符合條件的配對

```
while (right<nums.size())
{
  cur_pairs+=records[nums[right]];
  records[nums[right]]+=1;
  right++
}
```

當左指針右移移除 1 時，假設窗口內有 3 個 1，左指針右移除 1 時，被移除的 1 原本可以跟另外 2 個 1 各自組成一個配對，被移除後共減少(3-1)對符合條件的配對，寫法上先減少窗口內元素個數再減去配對數

```
while (left<right&&cur_pairs>k)
{
  records[nums[left]]-=1;
  cur_pairs-=records[nums[left]];
  left++;
}
```
