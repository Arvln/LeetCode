# 930.Binary-Subarrays-With-Sum

查子串或子數組，思路往滑動窗口上靠，右指針右移窗口內元素和會增加，左指針右移窗口內元素和會減少，當窗口內元素和大於目標和時左指針需要右移

```
while (left<right&&sum>target_sum)
{
  sum-=nums[left];
  left++;
}
```

累加窗口大小可以算出元素和最多為目標和的子數組數目，題目要求元素和恰好等於目標和的子數組數目，換個想法就是元素和最多為目標和的子數組數目減去元素和最多為目標和減 1 時的子數組數目，根據提示目標和可能為零，要處理邊界問題

```
if (target_sum==0) return at_most_k(nums, target_sum);
return at_most_k(nums, target_sum)-at_most_k(nums, target_sum-1);
```

比對目標和跟窗口內元素和有個技巧是進入窗口時，用目標和減去元素值，移出窗口時用目標和加上元素值，判斷左指針右移時機以目標和是否小於零判斷，這樣的好處有兩個

```
I. 不用額外聲明一個新變數cur_sum跟target_sum做比較
II. 某些測資較大，累加可能會溢出，利用左右指針右移互相抵銷的效果可避免結果溢出
```
