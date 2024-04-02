# 84.Largest-Rectangle-in-Histogram

這題關鍵在於從每根棒子的角度思考如何產生的最大面積。
固定當前棒子高度，向左可以延伸到前一根更矮的棒子，向右可以延伸到下一根更矮的棒子，因此當前棒子所能圍岀的最大面積為當前棒子高度乘上前一根更矮棒子與下一根更矮棒子間的距離。遍歷所有棒子可以形成的最大面積就可以得出答案。

```
maxArea[i]=heights[i]*(nextSmaller[i]-preSmaller[i]-1);
result=max{ maxArea[i] } for i=0,1,2,...,n-1
```

求下一個更大或更小元素是單調棧的經典應用，這題藉著維護單調遞增棧得出前後一個更小元素的位置，用來算出每根棒子可以形成的最大面積。假設棒子前面沒有一根更矮的棒子，預設值給-1，後面沒有更矮的棒子，預設值給heights的長度。
在遍歷過程中棧頂元素在彈棧過程中可以得知前後一根更矮棒子的位置，因此代碼可以簡化到一次遍歷。

```
int ret=0;
for (int i=0; i<n; i++)
{
    while (!Stack.empty()&&heights[Stack.top()]>heights[i])
    {
        int height=heights[Stack.top()];
        Stack.pop();

        int weight=i-Stack.top()-1;
        ret=max(ret, height*weight);
    }
    Stack.push(i);
}
```

這邊需要考慮兩個邊界情況。

- 棧中只有一個元素，不存在次高元素，試圖訪問前一根更矮棒子位置時，棧為空。
解法很簡單，在最前面補零，0不影響計算且比所有棒子都矮不會被彈出，確保棧底永遠有元素。

```
heights.insert(heights.begin(), 0);
```

- 假設所有元素為單調遞增，不存在下一根更矮棒子，因此不會觸發彈棧並更新結果。
解法類似，在最後面補零，0比所有棒子都矮，當遍歷完所有元素後會強制彈棧並更新結果。

```
heights.push_back(0);
```
