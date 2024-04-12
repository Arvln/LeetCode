# 5.Longest-Palindromic-Substring

問最值的問題思路可以往dp上靠。

```
i [X X X X X] j
```

- 思考對當前雙閉區間[i:j]如何更新最長回文子串？

當s[i]==s[j]且s[i+1, j-1]恰好是回文子串時，[i:j]區間內最長回文子串就是s[i:j]。

- 接著思考需要哪些狀態？

推導狀態需要區間的左右邊界i跟j。

- 藉由狀態定義dp數組。

```
dp[i][j]: s[i:j] is palindromic or not.
```

- 推導狀態轉移方程。

```
if (s[i]==s[j]&&dp[i+1][j-1]==true) dp[i][j]=true;
```

- 設定邊界條件及dp初始值。

大區間會依賴於較小區間，設定從區間長度為3開始遍歷，需要預先初始化長度為1、2的狀態。

```
vector<vector<bool>>dp(n, vector<bool>(n, false));

for (int i=0; i<n; i++) dp[i][i]=true;
for (int i=0; i+1<n; i++)
  if (s[i]==s[i+1]) dp[i][i+1]=true;
```
