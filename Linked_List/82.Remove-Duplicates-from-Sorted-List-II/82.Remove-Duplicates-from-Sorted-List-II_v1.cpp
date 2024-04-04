class Solution {
    unordered_map<int, int>Map; // val->count
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return NULL;

        Map[head->val]++;
        ListNode *back=deleteDuplicates(head->next);

        if (Map[head->val]==1) return new ListNode(head->val, back);
        else return back;
    }
};