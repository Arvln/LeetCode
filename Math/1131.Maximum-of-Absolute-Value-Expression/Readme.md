# 1131.Maximum-of-Absolute-Value-Expression

仔細觀察要求的數學式，可以發現是在三維空間中求任意兩點最大的曼哈頓距離。先從推導二維的最大曼哈頓距離下手。

- 拆絕對值

要拆絕對值需要分正負兩種情況討論，二維空間中有2^2種可能正負號分配方式。

```
{xi, yi}, {xj, yj}

max { |xi-xj| + |yi-yj| }
=> max {
  xi-xj + yi-yj,
  -(xi-xj) + yi-yj,
  xi-xj + -(yi-yj),
  -(xi-xj) + -(yi-yj)
}
=> max {
   xi-xj+yi-yj,
   -xi+xj+yi-yj,
   xi-xj-yi+yj,
   -xi+xj-yi+yj
}
```

- 將同一點的x跟y座標計算結果合併。

```
max {
  (xi+yi) - (xj+yj),
  (-xi+yi) - (-xj+yj),
  (xi-yi) - (xj-yj),
  (-xi-yi) - (-xj-yj)
}
```

- 對任意(i, j)兩點的x, y正負號分配的結果都算出來，取相減後的最大值就是最大的曼哈頓距離的可能候選。

```
max { |xi-xj| + |yi-yj| }
=> max for all (i, j) {
  max {
    (xi+yi) - (xj+yj),
    (-xi+yi) - (-xj+yj),
    (xi-yi) - (xj-yj),
    (-xi-yi) - (-xj-yj)
  }
}
```

- 將任意兩點(i, j)的計算轉成對所有點計算也成立。

```
max {
  max for all (i, j) { (xi+yi) - (xj+yj) },
  max for all (i, j) { (-xi+yi) - (-xj+yj) },
  max for all (i, j) { (xi-yi) - (xj-yj) },
  max for all (i, j) { (-xi-yi) - (-xj-yj) },
}
```

- 得出結論。

在k維空間中，有2^k種拆絕對值的可能方法。計算出所有拆法對應的最大值跟最小值再相減，就是該種拆法的最大距離。再對所有可能拆法的最大距離取最大值就行。
