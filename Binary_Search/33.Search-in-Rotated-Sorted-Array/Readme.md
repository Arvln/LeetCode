# 33.Search-in-Rotated-Sorted-Array

旋轉數組中二分搜索，跟 #153 思路一樣，都是先隨便切一半，左右兩子數組中有一個必為有序，處理完有序的數組後，再思考要捨棄哪一個子數組。當左子數組有序時，檢查目標值是否在左子數組中，在的話捨棄右子數組，反之淘汰左子數組。當右子數組有序時，檢查目標值是否在右子數組中，在的話捨棄左子數組，反之淘汰右子數組。