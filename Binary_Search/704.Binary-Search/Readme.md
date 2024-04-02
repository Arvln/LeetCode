# 704.Binary Search

在按升序排列的數組中求給定值，是二分搜索最基礎的應用，需特別注意區間定義，按定義來執行搜索，最常見將區間定義為雙閉區間或左閉右開。

- 雙閉區間中，右邊界也是候選，所以l==r時要進循環判斷，循環終止條件為l==r+1，更新左右邊界時須依循區間定義。

```
[l, r]

int l=0, r=nums.size()-1;
while (l<=r) 
{
  int mid=l+(r-l)/2;

  if (nums[mid]==target) return mid;
  else if (nums[mid]<target) l=mid+1;
  else if (nums[mid]>target) r=mid-1;
}
return -1;
```

- 左閉右開區間中，右邊界不是候選，所以l==r時不用再進循環判斷，循環終止條件為l==r，更新左右邊界時須依循區間定義。

```
[l, r)

int l=0, r=nums.size();
while (l<r) 
{
  int mid=l+(r-l)/2;

  if (nums[mid]==target) return mid;
  else if (nums[mid]<target) l=mid+1;
  else if (nums[mid]>target) r=mid;
}
return -1;
```
