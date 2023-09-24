# 795.Number-of-Subarrays-with-Bounded-Maximum

查子串或子數組，思路往滑動窗口上靠，滑動窗口的特性是當右指針走到一個臨界點會拖著左指針向右走，讓左指針被迫要更新的臨界點通常是跟要求的條件相關，通常是一個最值，解題思考的重點之一是釐清這個收縮左邊界的條件

```
while (left<right && condition)
  left++
```

要求[left, right]區間內子數組數目，換個想法是求窗口內最大元素是right的子數組數目減去窗口內最大元素是left-1的子數組數目

```
at_most_k(nums, right)-at_most_k(nums, left-1);
```

最後實作求最大元素是k的子數組數目就行，右指針每向右移一格增加的子數組數目等於[left, right)窗口大小

```
int at_most_k(vector<int>& nums, int k)
{
  int left=0, right=0, ret=0;
  while (right<nums.size())
  {
    right++;
    if (nums[right-1]>k)
      left=right;
    ret+=right-left;
  }
  return ret;
}
```
