# 325.Maximum-Size-Subarray-Sum-Equals-k

要找滿足前綴和表達式最長的子數組。

```
pre[i]-pre[j-1]==k
```

用哈希表紀錄前綴和第一次出現的位置，第一次出現的位置在最前面，對應的子數組也最長。接著搜子數組和為k的子數組並更新最長長度就行。注意要加一個虛擬頭才能涵蓋從索引0開始的子數組。
