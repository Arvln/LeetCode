# 445.Add-Two-Numbers-II

加法運算習慣上從低位開始運算方便進位操作，給定兩條鏈表恰好是順序且單鏈表無法逆序遍歷。直觀上逆序讀單鏈表就想到後序遍歷，不過兩條鏈表長度不等，後序遍歷數字不一定能對上。遞歸操作本質上就是操作棧，可以用兩個棧存對應數字再逐個相加構造數字和鏈表。
