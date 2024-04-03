# 947.Most-Stones-Removed-with-Same-Row-or-Column

行列相鄰的石子都可移除，問最多可以移除的石子數。畫圖模擬一下，可以發現以下這種石子分布最後只會剩三顆石頭，其餘都可以移除。

```
          X
          X
          X
          X
 XXXXXXXXXXXX
      X
      X
      X
      X
      X
      X
      X
                XX
                      X
                    XXXX
```

一個最暴力的想法就是建一幅無向圖，按照類似拓撲排序的思維，將所有度為1的石子依序移除。另一個想法是將所有行或列相同的石子視作一個集合，每個集合只能保留一顆石子，其他都要被移除，因此最大可移除石子數量就等於石子總數減去集合總數。辨別兩個元素是否在同一集合就是並查集的應用，為求方便以石子的索引作為id建立並集集，同時把所有同行同列的石子用兩個哈希表紀錄。

```
vector<int>parents;
int count; // 連通分量個數
unordered_map<int, vector<int>>rows; // row->ids
unordered_map<int, vector<int>>cols; // col->ids
```

遍歷兩個哈希表將所有同行同列石子併入同一個集合，就可以知道最少要保留的石子數。
