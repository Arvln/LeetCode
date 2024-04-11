class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return NULL;

        ListNode *back=deleteDuplicates(head->next);

        if (back==NULL) return head;
        else if (back->val==head->val) return back;
        else
        {
            head->next=back;
            return head;
        }
    }
};