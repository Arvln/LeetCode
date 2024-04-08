# 1457.Pseudo-Palindromic-Paths-in-a-Binary-Tree

求所有二叉樹從根到葉的節點值可能構成回文的路徑條數，可以聯想到一系列求二叉樹路徑和的題目，都是用DFS去搜所有可能路徑。路徑上所有節點構成的序列要能構成回文，代表每個數字都是兩兩成對，只有一個是不重複的，可以想到跟 #136 一模一樣，都是同一個套路，唯一不同是不是每條路徑上都滿足只有一個數字不重複的要件，沒辦法直接對每個節點值做異或運算。因為不同數字彼此做異或運算會干擾結果。

```
2 -> 3 -> 3
2 -> 3 -> 1
```

有一個巧妙的辦法可以解決這個問題，就是用二次冪。為什麼二次冪可以解決不同數字異或運算的問題？二次冪在二進制中只有一個1，不同數字的二次冪彼此異或，因為1所在位數不同，會得到兩個1，變成不是二次冪的數字，要是能構成回文，一定不會有不同數字互相異或的情況發生，異或結果仍會是某個節點值的二次冪。所以只要判斷異或結果是不是二次冪就行。

```
num&(num-1)==0
```