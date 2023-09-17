# 679.24-Game

本題與 #241 和 #2019 類似，計算表達式所有可能的結果，可以假設最後一個運算符是加在第 k 個元素和第 k+1 個元素之間

```
X  X  X  X
   k k+1
```

從[i..j]的元素組成表達式所有可能結果依賴於從[i..k]的元素組成的表達式和[k+1..j]的元素組成的表達式兩者所有可能結果根據四種運算符兩兩組合算出

```
for (int k=i; k<j; k++)
{
  for (int x : dp[i][k])
    for (int y : dp[k+1][j])
    {
      dp[i][j].push_back(x+y);
      dp[i][j].push_back(x-y);
      dp[i][j].push_back(x*y);
      if (y>0)
        dp[i][j].push_back(x/y);
    }
}
```

核心框架差不多，不過題意要求除法要進行實數除法，需要將數組元素處理為 double 類型

```
vector<double>nums(cards.begin(), cards.end());
```

數字順序跟運算符都不作限制，需要窮舉所有可能排列並計算所有運算符的運算結果

```
sort(nums.begin(), nums.end());
while(next_permutation(nums.begin(), nums.end()))
{
  unordered_set<double> dp=dfs(nums, 0, nums.size()-1);
}
```

最後遍歷一次計算結果檢查是否存在等於 24 的結果
