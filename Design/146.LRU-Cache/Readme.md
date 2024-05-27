# 146.LRU-Cache

需要維護一個紀錄key讀取順序的序列，當讀取key之後更新讀取順序。

```
key1, key2, key3, .., key10

get(key2);

key1, key3, .., key10, key2
```

很顯然數據結構要支持常數時間刪除任意位置數據，同時必須是有序的。數組只有刪除最後一個數據是常數時間，哈希表是無序的，滿足條件的只有鏈表。

```
list<int>keyList;
```

鏈表在讀數據時是線性時間，需要搭配哈希表獲取key對應的迭代器，用於修改鏈表。再搭配另一個哈希表獲取key對應的值。

```
unordered_map<int, list<int>::iterator>keyToIter;
unordered_map<int, int>keyToVal;
```

調用get函數，先查key是否存在，不存在則返回-1。存在key則在鏈表中刪除key並加到鏈表尾部，再更新迭代器，最後返回key對應的值。調用put函數可分情況討論，先調用get函數檢查key是否存在，如果key存在，get函數會自動更新鏈表及迭代器位置，只需要修改key對應的值。如果key不存在，則要檢查是否會超過容量，超過容量時需要移除鏈表頭部的key。最後再執行插入key操作就行。
