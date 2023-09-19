# 282.Expression-Add-Operators

求所有計算結果為目標和的表達式就是回溯找所有可能解，這題難點在乘號的計算，回想求解表達式字符串計算結果時使用類似棧的數據結構，在遍歷字串時帶乘號的數字會先與棧頂元素相乘再存入棧，按照這個思路，計算結果也拆分成 prev 和 last 兩部分存儲，遇到乘號時 last 優先跟當前數字相乘即可

```
void dfs(string& num, int& target, int pos, string path, long prev, long last)
```

接下來就是正常回溯思路，遍歷一次字串拆出數字計算

```
for (int i=pos+1; i<=num.size(); i++)
{
  string str=num.substr(pos, i-pos);
  long val=stol(str);

  if (path.empty())
    dfs(num, target, i, str, prev, val);
  else
  {
    dfs(num, target, i, path+'+'+str, prev+last, val);
    dfs(num, target, i, path+'-'+str, prev+last, -val);
    dfs(num, target, i, path+'*'+str, prev, last*val);
  }
}
```

遍歷到最後一個字串，prev+last 合併出完整的計算結果若等於目標和則將路徑加入數組
