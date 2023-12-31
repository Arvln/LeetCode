# 2019.The-Score-of-Students-Solving-Math-Expression

本題與 #241 和 #679 類似，計算表達式所有可能的結果，可以假設第 k 個運算符是最後一個運算符

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
          dp[i][j].insert(x+y);
        else if (c=='*')
          dp[i][j].insert(x*y);
      }
  }
}
```

提示條件中學生答案在[0..1000]即是可以排除大於 1000 的結果，可提高運算速度

```
if (c=='+'&&x+y<=1000)
  dp[i][j].insert(x+y);
else if (c=='*'&&x*y<=1000)
  dp[i][j].insert(x*y);
```

計算正確結果跟 #227 類似，需要維護一個類似棧的數據結構，優先級較低運算符的數字先壓入棧，優先級較高運算符直接更新棧頂元素，最後將棧內元素相加即可得出答案
