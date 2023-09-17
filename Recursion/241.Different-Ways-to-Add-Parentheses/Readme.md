# 241.Different-Ways-to-Add-Parentheses.cpp

本題與 #679 和 #2019 類似，計算表達式所有可能的結果，可以假設第 k 個運算符是最後一個運算符

```
X X X X X [k] X X X X X
```

從[i..j]的字串組成表達式所有可能結果依賴於從[i..k-1]的字串組成的表達式和[k+1..j]的字串組成的表達式兩者所有可能結果根據第 k 個運算符兩兩組合算出

```
for (int k=i; k<j; k++)
{
  char c=s[k];
  if (c=='+'||c=='-'||c=='*')
  {
    for (int x : dp[i][k])
      for (int y : dp[k+1][j])
      {
        if (c=='+')
          dp[i][j].push_back(x+y);
        else if (c=='-')
          dp[i][j].push_back(x-y);
        else if (c=='*')
          dp[i][j].push_back(x*y);
      }
  }
}
```

選擇自頂向下遞歸會更容易處理越界問題及進行剪枝操作，再搭配記憶化提升算法性能
