# 518.Coin-Change-II

有容量跟物品，顯然可以套用背包問題思路，物品可複選代表是完全背包問題。完全背包問題可以無限選取物品，不需要像01背包問題一樣存在標示物品的維度。01背包問題中物品只能取一次，考慮選擇某物品是基於前一輪尚未選擇該物品的狀態轉移過來。完全背包問題則直接從本輪選取物品的結果進行狀態更新，因此只需要開容量的維度。

要求組合數，物品是無序的，遍歷的次序很重要。需要先遍歷物品再遍歷容量，每個物品都只更新容量一次。比如物品有一枚1元硬幣及一枚5元硬幣，容量為6時，這一輪被1元硬幣更新時，只取到{1,1,1,1,1,1}，下一輪被5元硬幣更新，只取到{5,1}。

```
for (int coin : coins)
  for (int capacity=coin; capacity<=amount; capacity++)
    dp[capacity]+=dp[capacity-coin];
```

反之要求排列數，物品順序是有意義的，需要先遍歷容量再遍歷物品，每個容量都能被所有物品更新一次。這輪被一枚1元硬幣更新取到{1,5}，再被一枚5元硬幣更新取到{5,1}。

```
for (int capacity=0; capacity<=amount; capacity++)
  for (int coin : coins)
    if (capacity>=coin) dp[capacity]+=dp[capacity-coin];
```

題目要求組合數，因此要先遍歷物品再遍歷容量。
