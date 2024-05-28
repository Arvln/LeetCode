# 974.Subarray-Sums-Divisible-by-K

子數組和問題很容易聯想到前綴和，前綴和可以被k整除可轉換成數學式，思路跟 #560 差不多，只差在要多對k取餘數。

```
(pre[i]-pre[j-1])%k==0

pre[i]%k==pre[j-1]%k
```

等式實際代表在遍歷前綴和時，搭配哈希表紀錄前綴和對k取餘數對應的數組數量。在每次遍歷新數字時，檢查哈希表中是否存在對應前綴和餘數可搭配成合法子數組並累加子數組個數。特別注意前綴和可能為負數，整除的餘數可為負數，需處理為正數。

```
(presum%k+k)%k
```