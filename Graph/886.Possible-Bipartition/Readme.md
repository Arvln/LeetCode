# 886.Possible-Bipartition

常規二分圖判定問題，先建圖再準備一個標記數組跟顏色數組。接著遍歷一遍所有節點，將未被遍歷過的節點上色並執行BFS搜索，當前節點跟下一個節點不能上相同顏色，如果能成功為所有節點上色代表是二分圖。