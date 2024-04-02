# 648.Replace-Words

給一個字典要匹配最短的單詞，涉及字串高效地存取，可以聯想到用字典樹。構建符合條件的字串只需遍歷一次字串，逐個字符依照英文字母及空字符分別做對應處理即可。

```
for (int i=0; i<n; i++)
{
    ret.push_back(sentence[i]);
    if (sentence[i]!=' ')
    {
        if (node!=NULL)
        {
            node=node->next[sentence[i]-'a'];
            if (node!=NULL&&node->isEnd==true)
            {
                while (i<n&&sentence[i]!=' ') i++;
                i--;
            }
        }
    }
    else node=root;
}
```

特別留意當字根與字典樹中存儲字串匹配時，直接將遍歷指針指向空格前一位字母，配合每次循環結束自增一的操作，下一輪循環將從空格開始，避免漏掉空格的操作。
