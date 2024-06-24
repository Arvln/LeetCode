class Solution {
    unordered_map<int, int>Map; // val->count
public:
    ListNode* deleteDuplicatesUnsorted(ListNode *head) {
        if (head==NULL) return NULL;

        Map[head->val]++;
        ListNode *back=deleteDuplicatesUnsorted(head->next);

        if (Map[head->val]==1)
        {
            head->next=back;
            return head;
        }
        else return back;
    }
};