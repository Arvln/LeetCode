# 621.Task-Scheduler

跨度相關問題一般可以用堆模擬任務分派過程或用貪心法估算，求最少消耗時間，不需要構建整個過程，貪心法會更優。

- 堆模擬

每輪最多取到一個跨度的量，最後一輪有多少全取。特別注意堆會自動排序，因此該輪遍歷結束前不能直接把下一輪數量加入堆中。

- 貪心法

考慮最少需要消耗多少時間，先評估數量最多任務總數有多少。數量最多任務數搭配間隔數可以推估出計入冷卻時間最少需要多少時間可以完成所有任務。任務總數也可能超過最少所需花費時間，因此兩者取大就行。

```
AAAAAAABBBBBBBCCCCCCD, n=4

A B C D X
A B C X X
A B C X X
A B C X X
A B C X X
A B C X X
A B

result = (maxFreq-1)*(n+1)+count = (7-1)*(4+1)+2

--------------------------------------------------

AAAAAAABBBBBBBCCCCCCCDDDDDDEEEEEE, n=4

A B C D E
A B C D E
A B C D E
A B C D E
A B C D E
A B C D E
A B C

result = tasks.size() = 33
```
