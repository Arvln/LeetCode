# 97.Interleaving-String

- 觀察在s1[i]跟s2[j]的位置要如何做選擇？

```
Z Z Z Z Z Z Z Z Z ?

X X X X X X i
Y Y Y Y Y j
```

要知道s1[1:i]跟s2[1:j]能不能構成s3[1:i+j]可從最後一個字符開始看起，比對s1[i]、s2[j]是否跟s3[i+j]相等再檢查前面的部分是否能構成字串剩餘部分。

- 思考需要哪些狀態？

推導狀態需要s1當前元素的位置i和s2當前元素的位置j。

- 明確狀態後可以定義dp數組含義，照抄題目要求的目標。

```
dp[i][j]: whether s3 is formed by an interleaving of s1[1:i] and s2[1:j].
```

- 推導狀態轉移方程。

當s1[i]跟s3[i+j]相等且s1跟s2剩餘部分可交互組成s3剩餘部分，則s1跟s2可以交互構成s3。同理，當s2[i]跟s3[i+j]相等且s1跟s2剩餘部分可交互組成s3剩餘部分，則s1跟s2也可以交互構成s3。

```
if (s1[i]==s3[i+j]&&dp[i-1][j]==true) dp[i][j]=true;
else if (s2[j]==s3[i+j]&&dp[i][j-1]==true) dp[i][j]=true;
```

- 設定邊界條件及dp數組初始值。

假設s1、s2、s3都是空字串代表可以交互構成。當s2為空字串，要看s1跟s3是否相等，反之s1為空字串，要看s2跟s3是否相等。

```
dp[0][0]=true;

for (int i=1; i<=m; i++)
  dp[i][0]=s1[i]==s3[i]&&dp[i-1][0];

for (int j=1; j<=n; j++)
  dp[0][j]=s2[j]==s3[j]&&dp[0][j-1];
```

- 得出結論

dp[m][n]表示s1[1:m]跟s2[1:n]是否能構成s3[1:m+n]。
