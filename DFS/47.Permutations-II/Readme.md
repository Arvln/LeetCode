# 47.Permutations-II

找出包含重複元素數組的所有排列，相同元素不可複選，需要一個visited數組標記已選過的元素，要去除重複排列，先將原始數組排序，讓相同數字相鄰，並記錄最後一個完成回溯的數字，假如當前數字跟最後一個完成回溯數字一樣，代表當前數字的子樹跟前面已完成回溯的子樹一樣，會生成完全一樣的排列，必須跳過，否則會出現重複的排列。