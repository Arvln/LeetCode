# 1352.Product-of-the-Last-K-Numbers

算區間積可以預計算前綴積數組，唯一可能影響結果的數字只有0，需要特別處理。當區間內涵蓋0，區間積必為0，因此只需記錄一下最後一次出現0的位置，判斷是否在計算區間內就行。任何數除以1不影響結果，因此0在前綴積數組中用1表示。
