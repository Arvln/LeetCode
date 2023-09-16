# 491.Non-decreasing-Subsequences

求數組的遞增子序列，要先了解子序列就是數學中組合的概念，組合是一組無序的集合，排列則是有順序性的集合，要窮舉所有可能的組合第一個想法就是回溯算法，控制迴圈的起始點窮舉出所有組合

```
void dfs(vector& nums, int start)
{
  for (int i=start; i<nums.size(); i++)
    dfs(nums, i+1);
}
```

數組包含重複元素的情況下，回溯樹會產生結構相同的重複子樹，需要進行剪枝操作才能去除重複的組合，一般情形下可以先把數組排序讓重複元素彼此相鄰再一起做剪枝

```
sort(nums.begin(), nums.end());
for (int i=start; i<nums.size(); i++)
{
  if (i>start&&nums[i]==nums[i-1]) continue;
  dfs(nums, i+1);
}
```

不過根據題意，數組元素的順序是有意義的，不能排序，需要換個方式將重複元素做剪枝，可以在每一層遍歷時加上 visited 來避免遍歷重複元素

```
unordered_set<int>visited;
for (int i=start; i<nums.size(); i++)
{
  if (visited.find(nums[i])!=visited.end()) continue;

  visited.insert(nums[i]);
  dfs(nums, i+1);
}
```
