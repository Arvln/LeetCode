# 1288.Remove-Covered-Intervals

對起始點做排序，所有結束節點比第一個區間結束節點要靠前的區間都是完全重疊的可跳過。起始點相同區間要對結束節點做降序排，確保第一個區間不是重疊區間。

```
--------- (V)
------ (X)
  --- (X)
   --------- (V)
    ------ (X)
     ---- (X)
      ------------ (V)
```
