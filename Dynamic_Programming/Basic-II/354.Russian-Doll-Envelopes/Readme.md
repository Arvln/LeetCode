# 354.Russian-Doll-Envelopes

跟 #300 思路一模一樣，都是求最長遞增子序列長度。這題有兩個維度，先對寬度從小到大排序，再對高度求最長遞增子序列長度。這會有一個問題就是高度較大的信封可能跟高度較小的信封寬度相同，依據定義無法塞進同寬度的信封，因此僅對寬度升序不夠，還需要高度降序排。如此一來對高度求最長遞增子序列長度即可。一般有兩種求法，分別是dp跟貪心法，這題數據量較大dp會TLE。

- dp

將dp數組定義為以第i位信封結尾的最長遞增子序列長度，往前找高度較小的信封做狀態轉移，最後遍歷一遍搜最大長度。

- 貪心法

維持序列升序，下一個元素較小時，通過二分法搜索通過二分法搜索第一個大於等於該元素的數所在位置，把他替換成新元素，好處是序列維持升序同時數值大小下降，可以更容易接上後面過來的其他數字。

```
1, 2, 7, 3, 5

1, 2, 7 -> 1, 2, 3 -> 1, 2, 3, 5
```