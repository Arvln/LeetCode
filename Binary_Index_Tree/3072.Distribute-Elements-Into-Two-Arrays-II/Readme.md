# 3072.Distribute-Elements-Into-Two-Arrays-II

在不斷更新更新的arr1跟arr2中查找嚴格大於目標值的數字總數。需要動態查詢區間和可以運用樹狀數組提高效率，當數字存在負數或數字範圍相當大時，直接將數字作為樹狀數組索引不合適，需做數字做離散化處理。先將數字排序，再從小到大依序將數字映射到一個連續的索引範圍內。如此一來索引對應的數字大小順序不變，相對位置更密集，可避免索引越界並節省樹狀數組需要開闢的空間。後續用映射後的連續索引來更新、查詢樹狀數組就行。