# 152.Maximum-Product-Subarray

求連續子數組最大乘積，可套用Kadane's的思路，dp數組定義為以nums[i]為結尾的最大連續子數組乘積跟最小連續子數組乘積，最大乘積可能取或不取以nums[i-1]為結尾的最大連續子數組乘積或最小連續子數組乘積，因此可推出狀態轉移方程。

```
maxProd[i]=max({maxProd[i-1]*nums[i], minProd[i-1]*nums[i], nums[i]});
minProd[i]=min({maxProd[i-1]*nums[i], minProd[i-1]*nums[i], nums[i]});
```

連續子數組最大乘積可能以任意數字結尾，最後再遍歷一遍maxProd取最大值。
