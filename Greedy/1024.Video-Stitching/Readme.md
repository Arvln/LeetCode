# 1024.Video-Stitching

跟 #45 思路很類似，都是用貪心思路。最少幾個區間能填充整個範圍可以對起始端點排序，起始端點在第一個區間結束端點左側的區間都可以考慮一遍，看哪個區間結束端點在最右側。

```
---------
   ----
    ----
     ------------ (V)
      ----
       -------
```

以最右側的結束端點當作下一輪考慮基準，衡量起始端點在該結束端點右側的所有區間，看哪個結束端點在最右側。不斷依循此貪心思路直到結束端點超過目標為止。也可能不存在起始端點在結束端點左側的區間，代表沒有區間能跟該區間重疊，因此無法剪接完整影片。