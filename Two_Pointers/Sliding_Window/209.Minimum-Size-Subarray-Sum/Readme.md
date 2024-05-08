# 209.Minimum-Size-Subarray-Sum

子串問題可套用滑窗思路，要求子數組和從前綴和角度下手也可。

- 滑窗

子數組和大於等於目標和收緊左邊界，看能收到多緊。

- 前綴和

```
X X X X j X X X i

pre[i]-pre[j-1]>=target
```

考慮前綴和運算式，要達到目標和希望pre[j-1]越小越好，可以運用 #239 的思路來求滑動窗口最小值，雙端隊列維護一個單調遞增隊列，當隊尾元素指向前綴和大於當前元素，隊尾元素在後續配對中就算能達到目標和，所需要的區間長度也將大於當前元素，因此可以彈出。

```
while (!dq.empty()&&pre[dq.back()]>=pre[i])
  dq.pop_back();
```

隊首元素指向前綴和跟當前元素可以配對出目標和，但不見得是最短區間，因此可將該區間列入候選並彈出元素，考慮次小元素指向前綴和跟當前元素是否也可以配對出目標和，按此逐漸逼近最小區間長度。

```
while (!dq.empty()&&pre[i]-pre[dq.front()]>=target)
{
  ret=min(ret, i-dq.front());
  dq.pop_front();
}
```