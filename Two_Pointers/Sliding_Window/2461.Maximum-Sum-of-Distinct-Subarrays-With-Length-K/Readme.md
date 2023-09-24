# 2461.Maximum-Sum-of-Distinct-Subarrays-With-Length-K

子數組長度為 k 代表 left 跟 right 間距離超過 k 時，左指針要右移

```
if (right-left==k)
  left++;
```

要確定子數組內元素互不相同需要一個數組或哈希表紀錄元素個數，據此更新數組內唯一的元素個數，在窗口移動時同步更新窗口內元素和，當唯一的元素個數等於 k 時，代表窗口內元素互不相同，窗口內元素和可以跟結果取大
