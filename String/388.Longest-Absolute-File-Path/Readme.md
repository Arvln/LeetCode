# 388.Longest-Absolute-File-Path

找出最長文件路徑長度，即是路徑上每一層級所有資料夾、文件名長度跟斜槓的總和

```
"dir/subdir2/file.ext"

dir.size() + 1 + dir.size() + 1 + .. + file.size()
```

以\n 按層級將字串分割，再利用\t 個數判別所在層級將檔案名稱加入數組，以.判斷檔案是目錄或文件，是文件則計算文件的路徑長度並更新結果
