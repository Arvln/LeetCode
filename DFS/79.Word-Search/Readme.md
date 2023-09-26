# 79.Word-Search

搜索指定字串思路是靠 DFS 寫法最簡潔，先找到跟目標字串開頭一樣的字符開始 DFS，避免走回頭路要帶上 visited，搜到符合條件字串就可確定結果，DFS 給一個布爾返回值做剪枝

```
bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k, vector<vector<int>>& visited);
```

先看指針 k 有沒有搜完整個字串，還沒搜完先處裡越界問題再處理搜索過的字符跟與目標字串不符的字符，之後標記合法字符並往四個方向繼續擴散，定義方向數組需要注意使用 pair 效能更好且可解構，二維向量效能差可能超時

```
vector<pair<int, int>> dirs;
vector<vector<int>> dirs; -> TLE
```
