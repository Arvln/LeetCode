class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *s=head;
        while (head!=NULL&&head->next!=NULL)
        {
            head=head->next->next;
            s=s->next;
        }
        return s;
    }
};