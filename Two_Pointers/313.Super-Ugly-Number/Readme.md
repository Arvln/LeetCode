# 313.Super-Ugly-Number

#264 的 follow up，所有醜數是由 k 個鏈表合併出來的

```
1 -> 1*2 -> 2*2 -> 4*2 -> 7*2 -> 8*2 ...
1 -> 1*7 -> 2*7 -> 4*7 -> 7*7 -> 8*7 ...
1 -> 1*13 -> 2*13 -> 4*13 -> 7*13 -> 8*13 ...
1 -> 1*19 -> 2*19 -> 4*19 -> 7*19 -> 8*19 ...
```

求第 n 個醜數要合併 k 條鏈表，思路類似於 #23 用優先隊列依序推進鏈表元素

```
while (!pq.empty()&&cur==pq.top().first)
{
  int i=pq.top().second;
  pq.pop();
  pointers[i]+=1;
  pq.push({ret[pointers[i]]*primes[i], i});
}
```
