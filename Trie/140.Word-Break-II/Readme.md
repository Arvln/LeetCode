# 140.Word-Break-II

字串字典中每個字串前綴可能高度重合，將數組轉化成字典樹可提高查詢效率。要搜所有可能字串套用回溯思路。在每一輪分割字串時搭配字典樹匹配字符可提高剪枝的效率。