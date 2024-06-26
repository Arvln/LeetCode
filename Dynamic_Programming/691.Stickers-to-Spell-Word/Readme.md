# 691.Stickers-to-Spell-Word

目標字串長度最多15，這是很明顯的暗示可以用暴搜或狀態壓縮dp。狀態壓縮dp是以二進制表示目標以進一步規劃狀態轉移的思路。

- 思考在第i種狀態如何做選擇？

```
"thehat" -> 111111 -> dp[63]

"thea"  -> 111010 -> dp[58]
```

集滿t、h、e、a四種字符的最少貼紙張數再加上一張with貼紙就有機會更新集滿目標字串的最少貼紙張數。

- 思考需要哪些狀態？

需要表示二進制的狀態status。

- 明確dp數組的含義。

```
dp[status]: the minimum number of stickers that you need to spell out status.
```

- 推導狀態轉移方程。

集滿thehat字串可能有多種方式，比如先集滿ehat再使用with貼紙或集滿thea再使用with貼紙，當前狀態可能對應多個使用貼紙前的狀態，因此更新方式可用當前狀態計算出使用貼紙後的狀態再做更新。

```
dp[newStatus]=min(dp[newStatus], dp[status]+1);
```

- 設定邊界條件及dp初始值。

沒有拼出任何字符最少用0張貼紙當作邊界條件，要求最小值dp數組初始值設為最大值。

```
dp[0]=0;
```

- 得出結論。

集滿字符長度為n的字串需使用最少dp[(1<<n)-1]張貼紙。
