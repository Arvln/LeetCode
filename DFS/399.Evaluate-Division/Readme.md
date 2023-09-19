# 399.Evaluate-Division

給 A 到 B 的路徑求 C 到 D 的路徑，就是套一下回溯算法再看提示有沒有可以剪枝的條件，第一步先用鄰接表建一個有向圖，每個變數映射到除法運算的結果

```
A -> [{B, val1}, {C, val2}, {D, val3} ...]

unordered_map<string, vector<pair<string, double>>>map;
```

對每個 query 都做回溯看一下計算結果，將結果放入數組中，搜的是有環圖一樣要加 visited 避免走回頭路

```
vector<double>ret;
for (vector<string> query: queries)
{
  unordered_set<string>visited({query[0]});
  ret.push_back(dfs(query[0], query[1], visited));
}
```

要計算 A 除以 B 的結果有四種可能路徑，第一種情形返回 1.0，第二種查一下圖找到這條邊返回對應值就行，第三種要繼續遞歸搜尋圖才能確定，第四種返回-1.0

```
I. A==B
II. A->B
III. A->C->E-> .. -> B
IV. A無法到B
```

要處理 II.跟 III.的情形，遍歷所有 A 的有向邊找一個中間值 K 做比較，A 除以 K 取名為 A_K，若 K==B 就是 II.的情況，返回 A_K，若 K!=B 可以利用簡單分數計算原理，遞歸搜索 K 除以 B 的結果 K_B，將 A_K 乘上 K_B 當作結果返回

```
double dfs(int A, int B, unordered_set<string>& visited)
{
  if (A==B) return 1.0;

  for (auto [K, A_K] : map[A])
  {
    if (K==B) return A_K;
    if (visited.find(K)!=visited.end()) continue;

    visited.insert(K);
    double K_B=dfs(K, B, visited);
    visited.erase(K);
    if (K_B!=-1) return A_K*K_B;
  }
  return -1;
}
```
