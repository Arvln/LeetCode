# 692.Top-K-Frequent-Words

常規有兩種思路，一種是用二分搜索把前k大元素的頻率搜出來，再把大於該頻率的所有字串取出來排序，字串總數不一定剛好是k個，可能會有多，因此要將排名較靠後的多餘字串去掉。另一種是用堆排序再依序取排名前k個的字串，