# 1584.Min-Cost-to-Connect-All-Points

題目僅要求連通所有節點，沒有要求從特定起點出發，屬於最小生成樹的問題，直接套並查集套路，用堆排序連接每條邊的花費，再從最小花費開始逐個連通所有節點。