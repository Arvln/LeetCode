class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL||head->next==NULL) return head;

        ListNode *back=swapPairs(head->next->next);
        ListNode *ret=head->next;
        head->next->next=head;
        head->next=back;
        return ret;
    }
};