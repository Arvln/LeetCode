# 528.Random-Pick-with-Weight

要隨機抽取加權過的索引，一個直觀想法是既然隨機取數的機率是平均的，只要按權重增加對應數量的索引進數組中再隨機取數就行。

```
[1, 3, 2, 3, 1] -> [0, 1, 1, 1, 2, 2, 3, 3, 3, 4]
```

方法是可行，不過如果資料量太大，會很耗費空間，可以簡化成區間來進一步優化。

```
 0    1     2     3    4
[0] [1:3] [4:5] [6:8] [9]
```

依然是在總和中取隨機數，不過現在不必加入權重對應數量的索引，改用區間來代替，當隨機數落在某個對應區間就是取到該索引，隨機數同時代表前綴和。通過初始化前綴和數組標示每個索引的區間終點，在每次對總和取隨機數時，利用二分搜索可以找到第一個區間終點大於等於該隨機數的區間，再找出區間對應的索引就行。