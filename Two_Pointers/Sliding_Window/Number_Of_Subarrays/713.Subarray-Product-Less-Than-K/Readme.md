# 713.Subarray-Product-Less-Than-K

查子串或子數組，思路往滑動窗口上靠，靠右指針往前搜新元素，左指針按窗口內元素積變化被動向右拖行，由於窗口內元素積嚴格小於 K，左指針大於等於 K 都需要把最左側元素移出窗口並右移

```
while (left<right&&product>=k)
{
  product/=nums[left];
  left++;
}
```

右指針向右一格新增加的子數組數目就是窗口內元素配上新加入元素組成的所有子數組，在[left, right)區間內等於窗口大小

```
ret+=right-left;
```
