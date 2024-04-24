# 1438.Longest-Continuous-Subarray-With-Absolute-Diff-Less-Than-or-Equal-to-Limit

求子串長度很自然想到用滑窗思路，如何記錄子序列內最大和最小元素是關鍵，比較無腦可以直接用紅黑樹，滑動時更新樹上元素求出絕對差。絕對差是滑窗內最大值減去最小值，可以秒想到 #239 用雙端隊列求滑動窗口的最大值的思路，這邊用兩個雙端隊列分別維護滑窗最大值跟最小值，就可以算出子串內絕對差，雙端隊列插入、刪除操作性能也比紅黑樹更優。