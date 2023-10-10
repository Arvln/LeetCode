# 65.Valid-Number

判斷"+"、"-"、"e"、"E"、"."跟數字所有邊界情況，"+"、"-"只能出現在第一位或"e"、"E"後面第一位，"e"、"E"只能出現一次且只能在數字之間，前面的數是實數，後面的數是整數，"."只能出現一次且不可單獨出現，思路是先過一遍字串只保留"e"、"E"、"."和數字，其餘字符不影響判斷都去除

```
for (int i=0; i<s.size(); i++)
{
  if (s[i]=='+'||s[i]=='-')
  {
    if (i>0&&s[i-1]!='e'&&s[i-1]!='E') return false;
  }
  else if (s[i]!='e'&&s[i]!='E'&&s[i]!='.'&&!isdigit(s[i]))
    return false;
  else
    t.push_back(s[i]);
}
```

新字串 t 存在一些不合法的情況，原因是對"e"、"E"、"."即空值還沒進行處理，先處理 t 為空值及單獨出現"."的情況，"e"、"E"可後續統一處理

```
if (t.empty()||t==".") return false;
```

處理"e"、"E"重複出現、出現在頭尾、前面非實數的情況

```
if (t[i]=='e'||t[i]=='E')
{
  if (count_e) return false;
  if (i==0||i==t.size()-1) return false;
  if (!isNumber(t.substr(0, i))) return false;
  count_e+=1;
}
```

處理"."重複出現及出現在"e"、"E"後面形成非整數的情況

```
if (t[i]=='.')
{
  if (count_e||count_dot) return false;
  count_dot+=1;
}
```
