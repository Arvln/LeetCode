# 90.Subsets-II

序列元素有重複不可複選。求所有可能就是用回溯，元素有重複因此會出現重複子樹，要避免遍歷重複子樹可先將數組排序，讓重複數字相鄰，再跳過重複數字。不可複選元素因此選中元素後，下一個元素只能從後面剩餘的元素挑。