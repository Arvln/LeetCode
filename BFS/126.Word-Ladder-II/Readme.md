# 126.Word-Ladder-II

求所有可能的最短路徑。很常規的搜索題，要從某個單詞轉換成另一單詞只能有一個字符不同，按照這個定義先構建圖。特別注意起始單詞不一定在字典內，要先加入字典，構建圖時要比對單詞是否存在需要用一個集合來判斷。

```
wordList.push_back(beginWord);
unordered_set<string>Set(wordList.begin(), wordList.end());
```

建圖很直觀，逐個單詞把所有字母從a到z替換試試看是否在字典內，存在的話即可構成一條邊。接著套常規BFS思路求最短路徑。不同單詞可能指向同一單詞，要把所有可能路徑都搜出來。因此每走到一個單詞不能馬上將該單詞標記為已訪問，本輪另一條路徑可能正指向同一單詞。馬上做標記會錯失其他潛在路徑。

```
"hit" -> "hot"
"dot" -> "hot"
"hog" -> "hot"
```

解決方法很簡單，本輪用一個集合存下一輪元素，等到所有路徑都遍歷完，再加入隊列中。如此一來不只完整遍歷所有路徑，也避免重複將同一元素加入隊列造成冗余遍歷。到達終點時一樣要把該輪所有到達終點路徑都遍歷完再結束搜索。搜索時用哈希表紀錄所有前驅節點方便回溯所有可能路徑。最後套一下DFS把所有最短路徑搜出來。
