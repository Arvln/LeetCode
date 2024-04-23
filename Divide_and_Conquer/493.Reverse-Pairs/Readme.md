# 493.Reverse-Pairs

要求Count of Large Numbers Before Self跟#315 求Count of Smaller Numbers After Self差不多的想法，運用歸併排序讓兩個子數組有序的性質二分搜出第一個大於當前數字2倍的數所在位置並計算偏移量，可以知道有多少個符合條件的數字，每個數字代表一對合法數對。
