# 1022.Sum-of-Root-To-Leaf-Binary-Numbers

求二叉樹路徑和，跟 #112 系列的題目差不多思路。二叉樹解題思路不外乎兩種，一種是遍歷一遍樹，另一種是分解成單個節點能處理的小問題。當所有需要的資訊都在一顆節點中能獲取時，這兩種思路可隨便用，不過當題目要求的目標相對複雜時，可能出現需要跨多個節點的資訊做綜合判斷，就要有技巧地混用兩種思路來解題。要算出根到葉的二進位路徑和，每個節點要左移路徑和並加上當前節點值，有點類似反轉數字操作。關鍵在於採用哪種思路，這題要求的目標相對單純，單一節點內可以判斷是否是葉子節點，也可以得到子樹所有葉子節點的路徑和，因此完全可以用分解問題的思路，將DFS函數的定義照抄為返回題目要求解的目標，即所有根到葉的二進位路徑和。

```
target -> the sum of all paths from root to leaf
DFS -> the sum of all paths from root to leaf
```

另一種更通用的解法是將DFS函數定義為返回樹的深度，當遍歷到子樹的深度為1，也就是葉子節點時，更新答案，這是混用兩種思路的解法，雖然無法直接用DFS搜出答案，不過當題目求的目標更複雜時，會非常有用。

```
target -> the sum of all paths from root to leaf
DFS -> the depth of the tree
```