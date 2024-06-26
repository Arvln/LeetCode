# 698.Partition-to-K-Equal-Sum-Subsets

判斷是否能將數組分割成k個等和子集，先考慮數組能不能達成總和除以k的目標和該怎麼處理？這是DFS算法最基本的使用情境，現在題目只是多出數量k這個維度，依然可以用DFS處理。DFS可以從兩種不同思路切入，一種是以組別、一種是以數字。

- 組別為主

一個組別湊齊再湊下一組，先定義DFS函數，當選擇某個數字之後，我們不會再重複選擇該數，需要考察該數後面剩餘的數字，類似於組合不可複選元素，需要起始索引控制循環起點。還需要目標和以及湊齊目標和的次數。

```
bool dfs(vector<int>&nums, int cur, int sum, int count)
```

數字不能重複選擇，所以需要visited數組標記已選過的數字，邊界條件有兩個，一個是當湊齊目標和k次後代表可以成功分割，另一個是當本輪湊齊目標和後，繼續進行下一輪分割。還有一個重要的剪枝技巧，因為數組可以包含重複的元素，可以套用組合或排列去重方法，先將原始數組排序，讓相同數字相鄰，並記錄最後一個分割失敗的數字，假如當前數字跟前一個分割失敗的數相等，可以跳過。

- 數字為主

逐個數字分派到不同組別，當所有數字都成功分配到組別，代表可以順利分割。剪枝策略跟以組合為主差不多，某個組合和加上當前數字會分割失敗，另一個相同組合和也必失敗，可以直接跳過搜索。
