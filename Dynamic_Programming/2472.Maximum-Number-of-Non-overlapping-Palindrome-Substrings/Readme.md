# 2472.Maximum-Number-of-Non-overlapping-Palindrome-Substrings

跟 #3077 思路幾乎一模一樣，不過題面花樣比較少，優化思路跟 #1278 相同。

- 對於最後一個元素i可以做哪些選擇？

```
[X X X X X X X] [i]
```

不一定要取所有元素，因此最後一個元素可以取或不取。若要取則最後一個元素所在的子串長度需至少為k且要是回文串。

- 思考需要哪些狀態？

標示當前元素位置i。

- 定義dp數組含義。

```
dp[i]: the maximum number of substrings in s[1:i].
```

- 推導狀態轉移方程。

```
do not pick s[i]:
=> dp[i]=max(dp[i], dp[i-1]);

do pick s[i]:
=> if (s[j:i] size>=k && s[j:i] is palindrome) dp[i]=max(dp[i], dp[j-1]+1);   
```

- 設定邊界條件及dp數組初始值。

不一定要全選所有元素，因此前i個元素預設不選任何子串作為邊界條件且要求的是最大值，因此dp初始值可直接給0。

```
vector<int>dp(n, 0);
```

- 得出結論

求長度為N的字串s[1:N]中最大子串數量為dp[N]。
