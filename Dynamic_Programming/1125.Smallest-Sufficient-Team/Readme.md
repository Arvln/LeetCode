# 1125.Smallest-Sufficient-Team

跟 #691 思路幾乎一模一樣，目標字串長度最多16，這是很明顯的暗示可以用暴搜或狀態壓縮dp。狀態壓縮dp是以二進制表示目標以進一步規劃狀態轉移的思路。

- 思考在第i種狀態如何做選擇？

```
"java","nodejs","reactjs" -> 111 -> dp[7]

"nodejs","reactjs"  -> 011 -> dp[3]
```

集滿nodejs、reactjs兩種技能的最少組員數再加上一個會java的成員就有機會更新集滿所有需求技能的最少組員數。

- 思考需要哪些狀態？

需要表示二進制的狀態status。

- 明確dp數組的含義。

```
dp[status]: the smallest possible size of sufficient team status.
```

- 推導狀態轉移方程。

集滿所有需求技能的團隊可能有多種方式，比如先集滿java、nodejs再加上一個會reactjs的組員或集滿nodejs、reactjs再加上一個會java的組員，當前狀態可能對應多個加入組員前的狀態，因此更新方式可用當前狀態計算出加入組員後的狀態再做更新。

```
dp[newStatus]=min(dp[newStatus], dp[status]+1);
```

要求集滿所有需求技能的最少組員數團隊的所有組員索引，可在每次成功更新狀態時記錄一下前驅狀態及所選組員索引。

```
if (dp[newStatus]==dp[status]+1) pre[newStatus]={status, idx};
```

- 設定邊界條件及dp初始值。

沒有需求任何技能的團隊最少需0為組員當作邊界條件，要求最小值dp數組初始值設為最大值。

```
dp[0]=0;
```

- 得出結論。

集滿所需n個技能的最少組員數為dp[(1<<n)-1]，要求所有組員的索引，遍歷一遍所有前驅節點就行。
