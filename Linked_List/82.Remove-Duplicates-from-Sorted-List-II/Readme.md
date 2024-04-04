# 82.Remove-Duplicates-from-Sorted-List-II

鏈表節點本身是有序的，要求將節點值重複出現的節點刪除，返回剩餘節點構成的鏈表。鏈表本質上是一叉樹，因此樹有關的概念都可以組合使用。那思路就很簡單，無腦套DFS解決，在前序遍歷統計節點值出現次數，在後序遍歷時只保留出現一次的節點組合成鏈表。這邊用一個哈希表存節點值與出現次數的映射。

```
ListNode* deleteDuplicates(ListNode* head) {
    if (head==NULL) return NULL;

    Map[head->val]++;
    ListNode *back=deleteDuplicates(head->next);

    if (Map[head->val]==1) return new ListNode(head->val, back);
    else return back;
}
```

這種解法要多開空間，想降低空間消耗可以考慮用迭代來解，鏈表題只要涉及建構操作最好要準備一個哨兵節點，哨兵就是站在鏈表中的一枚虛擬頭節點，對避免各種邊界問題很有幫助。

```
ListNode *sentinal=new ListNode();
```

迭代過程中用快慢指針配合計數器更新下一個節點與結果。
