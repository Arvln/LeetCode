# 211.Design-Add-and-Search-Words-Data-Structure

高效存取字串是字典樹最基礎的應用，字典樹實現相當簡單，本質上是一棵多叉樹，根據題目只會出現小寫英文字母空間開26位定長數組存孩子節點，順便加一個布爾變量標示字串是否結束

```
class Node {
    public:
        Node *next[26];
        bool isEnd=false;
};
```

弄一個根節點來存所有字串

```
Node *root=new Node();
Node *cur=root;
for (char c : word)
{
    if (cur->next[c-'a']==NULL) cur->next[c-'a']=new Node();
    cur=cur->next[c-'a'];
}
cur->isEnd=true;
```

比較特別是搜尋單詞含有.可以匹配所有字符，這邊DFS搜一下找符合條件的字符即可，需要注意DFS終止條件有兩種，一種是還沒匹配完字串就沒路走，直接返回false。另一種是匹配完字串，該節點不是任一字串終點。

```
if (node==NULL) return false;
else if (i==s.size()) return node->isEnd==true;
```