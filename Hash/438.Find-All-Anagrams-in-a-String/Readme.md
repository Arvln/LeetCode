# 438.Find-All-Anagrams-in-a-String

處理子串、子數組問題因為涉及多個元素間關係，思路多半跟滑動窗口有關，根據題意要遍歷整個字串持續向右滑，當窗口大小等於目標字串長度時固定窗口大小一格一格向右滑動搜尋

```
int left=0, right=0;
while (right<s.size())
{
  right++;

  if (right-left==p.size())
    left++;
}
```

目標是匹配目標字串，即是比對一下當前窗口內是否湊齊目標字串的所有組成元素，需要用一個數據結構存儲當前窗口及目標字串的組成元素，可選用哈希表或數組

```
I. vector<int> ASCII -> count
II. unordered_map<char, int> character -> count
```

提示條件給定字串是由小寫英文字組成，數組大小開 26 位映射字元及對應個數，更新答案的時機在每次將字符移出窗口前比對一下窗口內組成元素是否與目標字串相等即可
